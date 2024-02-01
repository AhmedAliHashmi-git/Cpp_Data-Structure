#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node() : next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const string& data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    string getFront() {
        if (isEmpty()) {
            return "\0";
        } else {
            return front->data;
        }
    }
};

int main() {
    Queue ticketSalesQueue;
    Queue rollerCoasterQueue;
    Queue motionRideQueue;
    Queue roundWheelQueue;

    while (true) {
        int option;
        cout << "\nEnter an option:\n1. Enter visitor in the tickets purchase queue\n2. Sell a ticket \n3. Process all queues\n4. Quit\n";
        cin >> option;

        if (option == 1) {
            string name;
            cout << "Enter the visitor's name: ";
            cin>>name;
            ticketSalesQueue.enqueue(name);
            cout << "Visitor " << name << " added to the ticket purchase queue." << endl;
        } else if (option == 2) {
            if (!ticketSalesQueue.isEmpty()) {
                string visitorName = ticketSalesQueue.getFront();
                ticketSalesQueue.dequeue();
                cout << "Now Selling Ticket to " << visitorName << endl;
                int attractionOption;
                cout << "Select an attraction:\n1. Roller Coaster\n2. Motion Ride\n3. Round Wheel\n";
                cin >> attractionOption;

                if (attractionOption == 1) {
                    rollerCoasterQueue.enqueue(visitorName);
                    cout << "Visitor " << visitorName << " added to the Roller Coaster queue." << endl;
                } else if (attractionOption == 2) {
                    motionRideQueue.enqueue(visitorName);
                    cout << "Visitor " << visitorName << " added to the Motion Ride queue." << endl;
                } else if (attractionOption == 3) {
                    roundWheelQueue.enqueue(visitorName);
                    cout << "Visitor " << visitorName << " added to the Round Wheel queue." << endl;
                } else {
                    cout << "Invalid attraction option." << endl;
                }
            } else {
                cout << "Ticket purchase queue is empty." << endl;
            }
        } else if (option == 3) {
            cout << "Processing all queues:" << endl;
            while (!rollerCoasterQueue.isEmpty() || !motionRideQueue.isEmpty() || !roundWheelQueue.isEmpty()) {
                if (!rollerCoasterQueue.isEmpty()) {
                    cout << "Processing Roller Coaster queue: " << rollerCoasterQueue.getFront() << endl;
                    rollerCoasterQueue.dequeue();
                }
                if (!motionRideQueue.isEmpty()) {
                    cout << "Processing Motion Ride queue: " << motionRideQueue.getFront() << endl;
                    motionRideQueue.dequeue();
                }
                if (!roundWheelQueue.isEmpty()) {
                    cout << "Processing Round Wheel queue: " << roundWheelQueue.getFront() << endl;
                    roundWheelQueue.dequeue();
                }
            }
        } else if (option == 4) {
            cout << "Exiting the program." << endl;
            return 0;
        } else {
            cout << "Invalid option. Please enter a valid option." << endl;
        }
    }

}
