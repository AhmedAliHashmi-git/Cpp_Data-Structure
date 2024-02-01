#include <iostream>
using namespace std;

class Node {
public:
    string val;
    Node *next;

    Node(string val) {
        this->val = val;
        next = NULL;
    }
};

class Stack {
public:
    Node *top;

    Stack() {
        top = NULL;
    }

    ~Stack() {
        // Add logic to free memory if needed
    }

    bool isEmpty() {
        return (top == NULL);
    }

    void push(string val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return "";
        }
        Node *temp = top;
        string poppedValue = temp->val;
        top = top->next;
        delete temp;
        return poppedValue;
    }
};

class Queue {
    int front;
    int rear;
    int size;
    string *arr;

public:
    Queue(int size) {
        front = -1;
        rear = -1;
        this->size = size;
        arr = new string[size];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(string val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return "";
        }
        string dequeuedValue = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return dequeuedValue;
    }

    void getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    int choice;

    // Set up the stack for encounters
    Stack encounters;

    Queue mansionQueue(6);
    mansionQueue.enqueue("The Gateway to Darkness");
    mansionQueue.enqueue("The Creeping Corridor");
    mansionQueue.enqueue("The Abandoned Lounge");
    mansionQueue.enqueue("The Haunted Gallery");
    mansionQueue.enqueue("The Shadowed Library");
    mansionQueue.enqueue("The Broken Window");

    cout << "Start exploring the mansion? " << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;

    if (choice == 1) {
        while (!mansionQueue.isEmpty()) {
            cout << "Current Area: " << mansionQueue.dequeue() << endl;

            // Simulate encounters and push them onto the stack
            cout << "Encounter in " << encounters.pop() << endl;

            // Ask if the user wants to continue exploring
            cout << "Continue exploring? (1/0): ";
            cin >> choice;

            if (choice == 0) {
                cout << "See you next time" << endl;
                break;
            }
        }

                // Check if there are any remaining encounters in the stack
        while (!encounters.isEmpty()) {
            cout << "Current Encounter: " << encounters.pop() << endl;

            // Ask if the user wants to continue exploring
            cout << "Continue exploring? (1/0): ";
            cin >> choice;

            if (choice == 0) {
                cout << "See you next time" << endl;
                return 0;
            }
        }

        // If both the queue and the stack are empty, the exploration is complete
        cout << "Congratulations! You've explored the entire mansion." << endl;
    } else {
        cout << "See you next time" << endl;
        return 0;
    }

    return 0;
}

