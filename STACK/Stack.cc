#include<iostream>
using namespace std;
struct Node{
     Node* next;
     int info;
};

class Stack{
    Node* head;
    Node* temp;

    public:

    Stack(){
        head = NULL;
        temp = NULL;
    }
    
    void push(){
        if(head == NULL){
            head = new Node;
            cout<<"Enter a value: ";
            cin>>head->info;
            head->next = NULL;
            return;
        }
        temp = head;
        Node* temp1 = new Node;
        cout<<"Enter a value for new Node: ";
        cin>>temp1->info;
        temp1->next = temp;
        temp = head  = temp1;
        return;
    }

    void pop(){
       if(head == NULL){
        cout<<"Stack is empty: \n";
        return;
       }
       temp = head;
       if(temp->next == NULL){
        delete temp;
        head = NULL;
        return;
       }
       Node* temp1;
       while (temp->next->next != NULL)
       {
        temp = temp->next;
       }
       temp1 = temp->next;
       temp->next = temp->next->next;
       delete temp1;
       return;
       
    }
 


    void print(){
        if(head == NULL){
            cout<<"Stack is Empty: \n";
            return;
        }
        temp = head;
        while(temp != NULL){
          cout<<temp->info<<" ";
          temp = temp->next;
        }cout<<endl;
    }

};

int main(){
    Stack stc;
    stc.push();
    stc.print();
    stc.push();
    stc.print();
    stc.push();
    stc.print();
    stc.push();
    stc.print();
    stc.push();
    stc.print();
    cout<<endl;
    cout<<endl;

    stc.pop();
    stc.print();
    stc.pop();
    stc.print();
    stc.pop();
    stc.print();
    stc.pop();
    stc.print();

}

