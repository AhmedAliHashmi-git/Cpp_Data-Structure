#include<iostream>
using namespace std;
struct Node{
     int info;
     Node* next;
};
class LinkList{
    private:
    Node* head;
    Node* temp;
    Node* temp1;

    public:
    LinkList();
    ~LinkList();
    void addInsert();
    void remove();
    void print();
};
LinkList :: LinkList(){
    head = temp = temp1 = NULL;
}
LinkList ::~LinkList(){
    delete head ;
    delete temp ;
    delete temp1;
} 

void LinkList :: addInsert(){
    while(head == NULL){
       head = new Node;
       cout<<"Enter the value: ";
       cin>>head->info;
       head->next = NULL;
       return;
    }
    temp = head;
    int key;
    cout<<"Enter the key after you want to insert: ";
    cin>>key;
    bool found = false;
    while(temp != NULL){
        if(temp->info == key){
            temp1 = new Node;
            cout<<"Enter the value you want to insert: ";
            cin>>temp1->info;
            temp1->next = temp->next;
            temp->next = temp1;
            found = true;
        }
        temp = temp->next;
        
    }
    if(!found){
        cout<<"Number is not in the List"<<endl;
    }
             
}
void LinkList :: remove(){
    temp = head;
    int key;
    bool found=false;
    cout<<"Enter the key you want to delete: ";
    cin>>key;
    if(temp == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if (temp != NULL && temp->info == key) {
        head = temp->next; 
        delete temp; 
        return;
    }
    while(temp != NULL){
        if(temp->next != NULL && temp->next->info == key){
            temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
            found = true;
        }
        temp = temp->next;
    }
    if(!found){
        cout<<"Item did'nt found"<<endl;
    }
}
void LinkList :: print(){
    temp = head;
    while(temp != NULL){
        cout<<temp->info<<" ";
        temp = temp->next;
    }cout<<endl;
}


int main(){
    LinkList LL;
    int op;
    while(true){
    cout<<"Enter your choice: ";
    cin>>op;
    if(op == 1){
        LL.addInsert();
        }
    else if(op == 2){
        LL.print();
    }
    else if(op == 3){
        LL.remove();
    }
    }
}