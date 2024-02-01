#include<iostream>
using namespace std;

struct Node
{
    string list;
    bool comp; 
    Node* next;
    Node* previous;
};

class DoublyLinkedList
{
private:
    Node* head;
    int length;

public:
    DoublyLinkedList() {
        length = 0;
        head = NULL;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int pos) {
        cout << "Enter the task description: ";
        string task;
        cin >> task;

        if (pos < 1 || pos > (length + 1)) {
            cout << "Invalid position" << endl;
            return;
        }
        
        Node* newNode = new Node;
        newNode->list = task;
        newNode->comp = false;

        if (pos == 1) {
            newNode->next = head;
            newNode->previous = nullptr;
            if (head != nullptr) {
                head->previous = newNode;
            }
            head = newNode;
        }
        else {
            Node* curr = head;
            for (int i = 1; i < (pos - 1); i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            newNode->previous = curr;
            if (curr->next != nullptr) {
                curr->next->previous = newNode;
            }
            curr->next = newNode;
        }
        length++;
    }

    bool complete() {
        int num;
        cout << "Enter the task Number you want to mark as Complete: ";
        cin >> num;

        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (position == num) {
                temp->comp = true; 
                return true;
            }
            temp = temp->next;
            position++;
        }
        return false;
    }

    void removeCompleted() {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->comp) { 
                if (temp->previous != nullptr) {
                    temp->previous->next = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->previous = temp->previous;
                }
                if (head == temp) {
                    head = temp->next;
                }
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
                length--;
            }
            else {
                temp = temp->next;
            }
        }
    }
void print() {
    int choice;
     if (head == nullptr) {
        cout << "List is Empty!!!" << endl;
        return;
    }
    cout<<"Display tasks in forward or reverse order?\n1). Forward \n2). Reverse\n";
    cin>>choice;
    
    if(choice == 1){
     Node* temp = head;
    while (temp != nullptr) {
        string comp;
        if (temp->comp) {
            comp = "Completed";
        } else {
            comp = "Not Completed";
        }
        cout << temp->list << " -- " << comp << endl;
        temp = temp->next;
    }
    cout << endl;
}
else if (choice == 2) {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            string comp;
        if (temp->comp) {
            comp = "Completed";
        } else {
            comp = "Not Completed";
        }
            cout << temp->list << " -- " << comp << endl;
            temp = temp->previous;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }
    }
   

   

};

int main() {
    int op;
    DoublyLinkedList dll;

    while (true) {
        cout << "1) Add Task.\n2) Mark as Completed.\n3) Remove Complete tasks.\n4) Display Tasks.\n5) Quit." << endl;
        cout << "Please Enter your choice: ";
        cin >> op;

        if (op == 5) {
            break; 
        }
        else if (op == 2) {
            bool found = dll.complete();
            if (!found) {
                cout << "Task not found." << endl;
            }
        }
        else if (op == 1) {
            int pri;
            cout << "Enter the priority: ";
            cin >> pri;
            dll.add(pri);
        }
        else if (op == 3) {
            dll.removeCompleted();
        }
        else if (op == 4) {
            dll.print();
        }
    }

}
