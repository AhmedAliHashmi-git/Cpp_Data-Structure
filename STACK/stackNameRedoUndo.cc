#include<iostream>
using namespace std;
struct Node{
   Node* next;
   char name;
   Node(){
    next = NULL;
    name = ' ';
   }
};

class StackRedoUndo{
      Node* top;
      int length;
      int limit;
      public:
      StackRedoUndo(int limit) : limit(limit){
         length = 0;
         top = NULL;
      }
      ~StackRedoUndo(){
            while(!isEmpty()){
                  pop();
            }
      }

      bool isEmpty(){
            if(top == nullptr){
                  cout<<"Stack is Empty!!!\n";
                  return true;
            }
            return false;
      }
      bool isFull(){
            if(length == limit){
                  cout<<"Stack is Full!!!\n";
                  return true;
            }
            return false;
      }
      void push(char name){
          if(isFull()){
            cout<<"Stack is Full!!!\n";
            return;
          }
          Node* temp = new Node;
          temp->name = name;
          temp->next = top;
          top = temp;
          length++;
          return;
      }
      char pop(){
         if(isEmpty()){
            cout<<"Stack is empty!!!\n";
            return '\0';
         }
         Node* temp = top;
         char a = top->name;
         top = top->next;
         delete temp;
         temp = nullptr;
         length--;
         return a; 
      }
      void display(){
            if(isEmpty()){
                  cout<<"Stack is Empty!!!\n";
                  return;
            }
            Node* temp = top;
            while(temp != NULL){
                  cout<<temp->name;
                  temp = temp->next;
            }cout<<endl;
      }
};

void forward(StackRedoUndo &stc,string name){
      if(!stc.isFull()){
            for(int i = name.length()-1 ; i >= 0 ; i-- ){
                  char a = name.at(i);
                  stc.push(a);
            }
            stc.display();

      }
}
int main(){
      StackRedoUndo stc(5);
      StackRedoUndo stc2(5);
      string name;
      int op;
      char a;
      char b;
      cout<<"Enter the word: ";
      cin>>name;
      forward(stc , name);
      while(true){
      cout<<"Select Choice: \n 1-Undo. \n 2-Redo.\n ";
      cin>>op;
      switch (op)
      {
      case 1:
             
             a = stc.pop();
             stc.display();
             stc2.push(a);
            break;
      case 2:
            b = stc2.pop();
            stc.push(b);
            stc.display();
            break;
      default:
            cout<<"Invalid Option!!!\n";
            break;
      }
      }
      
}