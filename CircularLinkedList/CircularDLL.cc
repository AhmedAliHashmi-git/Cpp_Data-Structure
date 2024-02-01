#include<iostream>
using namespace std;
struct Node{
    int info;
    Node* next;
    Node* previous;
};
class CircularDoublyLL{
    private:
    Node* head;
    public:
     CircularDoublyLL();
        // ~CircularDoublyLL();
        void addInsert();
        void remove();
        void update();
        void print();
};
CircularDoublyLL :: CircularDoublyLL(){
    head = nullptr;
}
void CircularDoublyLL :: addInsert(){
    if(head == nullptr){
        head = new Node;
        cout<<"Enter the value: ";
        cin>>head->info;
        head->next = head;
        head->previous = head;
        return;
    }
    int key;
    Node* temp = head;
    cout<<"Enter the key: ";
    cin>>key;
    do{
        if(temp->info == key){
        Node* temp1 = new Node;
        cout<<"Enter the new value: ";
        cin>>temp1->info;
        temp1->next = temp->next;
        temp1->previous = temp;
        temp->next->previous = temp1;
        temp->next = temp1;
        return;
        }temp=temp->next;
        
        
    }while(temp != head);
    cout<<"Not found!!!\n";

}
void CircularDoublyLL::remove() {
    if (head == NULL) {
        cout << "List is Empty\n";
        return;
    }
    int key;
    cout << "Enter the Key you want to delete: ";
    cin >> key;
    Node* temp = head;
    do {
        if (temp->info == key) {
            Node* temp1 = temp;
            if (temp->next == temp) { 
                head = NULL;
            } else {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                if (temp == head) {
                    head = temp->next; 
                }
            }
            delete temp1;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found!!!!\n";
}

void CircularDoublyLL::print() {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main(){
    CircularDoublyLL CDLL;
    CDLL.addInsert();
    CDLL.print();
    CDLL.addInsert();
    CDLL.print();
    CDLL.addInsert();
    CDLL.print();
    CDLL.addInsert();
    CDLL.print();
    CDLL.addInsert();
    CDLL.print();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    CDLL.remove();
    CDLL.print();
    CDLL.remove();
    CDLL.print();
    CDLL.remove();
    CDLL.print();
}
