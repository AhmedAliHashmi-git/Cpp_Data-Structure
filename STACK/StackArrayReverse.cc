#include<iostream>
using namespace std;
class StackArray{
    int top;
    char* arr;
    int size;

    public:
    StackArray(int size) : size(size){
        top  = -1;
        arr = new char[size];
    }

    ~StackArray(){
        delete[] arr;
    }

    bool isEmpty(){
        if(top == -1){
            cout<<"Stack is Empty!!!\n";
            return true;
        }
        return false;
    }

    bool isFull(){
        if(top == size - 1){
            cout<<"Stack is Full!!!\n";
            return true;
        }
        return false;
    }

    void push(char word){
        if(!isFull()){
            top++;
            cout<<"Charcter "<<word<<" is pushed in the stack!!!\n";
            arr[top] = word;
            return;
        }
        cout<<"Stack if Full!!!\n";
        return;
    }


    char pop(){
        if(isEmpty()){
            cout<<"Stack is Empty!!!\n";
            return '\0';
        }
        char popped = arr[top];
        // cout<<"Character is "<<arr[top]<<" popped \n";
        top--;
        return popped; 
    }

    void peep(){
        if(!isEmpty()){
            cout<<"The top element is: "<<arr[top]<<endl;
            return;
        }
        cout<<"Stack is Empty!!!\n";
        return;
    }

    void reverse(string name){
        for(int i = 0 ; i < name.length() ; i++){
            char a = name[i];
            push(a);  
    }
    while(!isEmpty()){
        cout<<pop();
    }cout<<endl;
}
};


int main(){
    StackArray stc(5);
    string name = "ahmed";
    stc.reverse(name);

}