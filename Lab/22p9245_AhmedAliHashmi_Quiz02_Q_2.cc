#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int info;
    Node() : next(nullptr) {}
};

class SRL {
    Node* head;

public:
    SRL() : head(nullptr) {}
    ~SRL();
    void insert();
    void remove();
    void update();
    void print();
    void menu();
};

SRL::~SRL() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        if (next == head) {
            break;
        }
        current = next;
    }
}

void SRL::insert() {
    Node* newNode = new Node;
    cout << "Enter the value: ";
    cin >> newNode->info;

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        cout << "Value inserted." << endl;
        return;
    }

    Node* temp1 = head;
    do {
        if (newNode->info == temp1->info) {
            cout << "Value already present!!!" << endl;
            delete newNode;
            return;
        }
        temp1 = temp1->next;
    } while (temp1 != head);

    int key;
    cout << "Enter the Number after which you want to insert: ";
    cin >> key;
    Node* temp = head;

    do {
        if (temp->info == key) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Value inserted." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key not found!!!" << endl;
    delete newNode; 
}

void SRL::update() {
    int key;
    cout << "Enter the number you want to update: ";
    cin >> key;
    int val;
    Node* temp = head;
    do {
        if (temp->info == key) {
            cout << "Enter the updated value: ";
            cin >> val;
            temp->info = val;
            cout << "Value updated." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Key not found!!!" << endl;
}

void SRL::remove() {
    int key;
    cout << "Enter the key you want to delete: ";
    cin >> key;
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }
    if (head->info == key) {
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        cout << "Value removed." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        if (temp->next->info == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Value removed." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found." << endl;
}

void SRL::print() {
    if (head == nullptr) {
        cout << "List is Empty!!!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != head);

    Node* temp1 = head;
    int count = 0;
    do{
       temp1 = temp->next;
       count++;
    }while(temp1->next != head);
     Node* temp2 = head;
    for(int i = 0 ; i < count/2 ; i++){
       
        temp2 = temp2->next;

    }
     temp = head;
    bool check = false;
    while(temp2 != head){
      if(temp->info != temp2->info){
        check = true;
        break;
      }
    }
    if(!check){
        cout<<"Not a palindrome Number!!!\n";
    }
    else {
        cout<<"Palimdrome Number\n";
    }
    cout << endl;
}

void SRL::menu() {
    int choice;

    do {
        cout << "Choose an option:\n";
        cout << "1. Insert\n";
        cout << "2. Print\n";
        cout << "3. Update\n";
        cout << "4. Remove\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                print();
                break;
            case 3:
                update();
                break;
            case 4:
                remove();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 5);
}

int main() {
    SRL srl;
    srl.menu();
}
