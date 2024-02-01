#include<iostream>
using namespace std;
struct Node{
  Node* next;
  int info;  
};
class Stack{
   Node* top;
   Node* temp;
   public:
   Stack(){
    top = temp = nullptr;
   }

   int push(){
    if(top == nullptr){
        top= new Node;
        cout<<"Enter first value: ";
        cin>>top->info;
        top->next = nullptr;
        return top->info; 
    }
    temp = top;
    Node* temp1 = new Node;
    cout<<"Enter second value: ";
    cin>>temp1->info;
    temp1->next = temp;
    top = temp = temp1;
    return temp1->info;
   }

   int pop(){
    if(top == nullptr){
        cout << "Stack is empty. Cannot pop." << endl;
        return -1;  
    }

    int a = top->info;
    temp = top;
    top = top->next;
    delete temp;
    return a;
}

   void print(){
    if(top == nullptr){
        cout<<"Stack is Empty!!!\n";
        return;
    }
    temp = top;
    while(temp!=nullptr){
        cout<<temp->info<<" ";
        temp = temp->next;
    }
    cout<<endl;
   }
};


int main(){
    Stack stc;
    cout<<"Before Swapping: \n";
    int a = stc.push();
    int b = stc.push();
    cout<<a<<" "<<b<<endl;
    a = stc.pop();
    b = stc.pop();
    cout<<a<<" "<<b<<endl;


}