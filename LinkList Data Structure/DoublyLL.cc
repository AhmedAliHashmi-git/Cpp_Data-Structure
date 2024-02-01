#include<iostream>
using namespace std;
struct Node{
   int info;
   Node* next;
   Node* previous;  
};
class DoubleLinkedList{
    private:
    Node* head;
    Node* temp;
    Node* temp1;
    public:
    DoubleLinkedList();
    void add();
    void print();
    void remove();
};
DoubleLinkedList::DoubleLinkedList(){
    head = temp = temp1 = NULL;
}

void DoubleLinkedList :: add(){
    if(head == NULL){
      head = new Node;
      cout<<"Enter the value: ";
      cin>>head->info;
      head->next = NULL;
      head->previous = NULL;
    }
    else{
        int key;
        cout<<"Enter the Key: ";
        cin>>key;
        temp = head;
        bool found= false;
        while (temp != NULL)
        {
            if(temp->info == key){
                temp1 = new Node;
                cout<<"Enter the value: ";
                cin>>temp1->info;
                temp1->next = temp->next;//1
                temp1->previous = temp;//2
                if(temp->next != NULL){
                    temp1->next->previous = temp1;//3
                }
                
                temp->next = temp1;//4
                found = true;
                break;
            }temp= temp->next;
        }
        if(!found){
         cout<<"Item did'nt found!!!\n";
         return;
        }
        temp = temp1 = NULL;
        
    }
}
void DoubleLinkedList :: remove(){
    int key;
    bool found = false;
    cout<<"Enter the key: ";
    cin>>key;
    
        temp = head;
        while(temp != NULL){
            if(temp->info == key){
            temp1 = temp;
            if( temp->previous != NULL){
                temp->previous->next = temp->next;
            }
            if(temp->next != NULL){
            temp->next->previous = temp->previous;
            }
            if(head == temp){
                head = temp->next;
            }
             delete temp;
            found = true;
            return;
            }
            
           
            temp = temp->next;
           
        }
    if(!found){
        cout<<"Not found!!!\n";
    }
}
void DoubleLinkedList :: print(){
    if(head == NULL){
        cout<<"List is Empty!!!\n";
        return;
    }
    temp = head;
    while(temp != NULL){
        cout<<temp->info<<endl;
        temp = temp->next;
    }cout<<endl;
}

int main(){
    DoubleLinkedList dll;
    int op;
    while(true){
        cout<<"Enter your choice: ";
        cin>>op;
        if(op == 1){
            dll.add();
            dll.print();
        }
        else if(op == 2){
            dll.print();
        }
        else if(op == 3){
            dll.remove();
            dll.print();
        }
    }
}

