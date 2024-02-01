#include<iostream>
using namespace std;
struct Node{
   Node* next;
   int info;
};
class dublicate{
   Node* head;
   bool check;
   public:
    dublicate(){
    head = nullptr;
    check = false;
   }
   void add(){
    if(head == NULL){
      head = new Node;
      cout<<"Enter the value: ";
      cin>>head->info;
      head->next = NULL;
      return;
    }
    int key;
    Node* temp = head;
    cout<<"Enter the key: ";
    cin>>key;
    while(temp!= NULL){
      if(temp->info == key){
        Node* temp1 = new Node;
        cout<<"Enter the new value: ";
        cin>>temp1->info;
        temp1->next = temp->next;
        temp->next = temp1;
        return;
      }temp = temp->next;
    }
    cout<<"Item did'nt found!!!\n";

   }
   void display(){
    if(head == NULL){
      cout<<"List is empty!!!\n";
      return;
    }
    Node* temp = head;
    while(temp != NULL){
      cout<<temp->info;
      temp= temp->next;
      }
      
    }
   void print() {
    if (head == NULL) {
        cout << "List is empty!!!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        bool check = false; 
        for (Node* temp1 = head; temp1 != NULL; temp1 = temp1->next) {
            if (temp->info == temp1->info && temp != temp1) {
                check = true;
                break; 
            }
        }
        if (check) {
            cout<<"\nDublicate Number is: "<<temp->info << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

    
   
};



int main()
{
      dublicate dub;
      dub.add();
      dub.add();
      dub.add();
      dub.add();
      dub.add();
      dub.display();
      dub.print();
}