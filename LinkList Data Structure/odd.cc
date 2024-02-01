#include<iostream>
using namespace std;
struct Node{
   Node* next;
   int info;
};
class EvenOdd{
   Node* head;
   public:
   EvenOdd(){
    head = nullptr;
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
   void print(){
    if(head == NULL){
      cout<<"List is empty!!!\n";
      return;
    }
    Node* temp = head;
    while(temp != NULL){
      if(temp->info % 2 == 0){
        cout<<"Even Number are: "<<temp->info<<endl;
      }
      else {
        cout<<"Odd Number are: "<<temp->info<<endl;
      }temp= temp->next;
      
    }cout<<endl;
   }
};


int main()
{
      EvenOdd eo;
      eo.add();
      eo.add();
      eo.add();
      eo.add();
      eo.add();
      eo.print();
}



