#include<iostream>
using namespace std;
class StackArrayReverse{
    int top;
    int size;
    int* arr;

    public:
    StackArrayReverse(int size) : size(size){
        top = -1;
        arr = new int[size];
    }

    bool isEmpty(){
        if(top == -1){
            cout<<"Array is Empty!!!\n";
            return true;
        }
         return false;
    }
    bool isFull(){
        if(top == size - 1){
            cout<<"Array is Full!!!\n";
            return true;
        }
        return false;
    }
    void push(int val){ 
        if(!isFull()){
            top++;
            arr[top] = val;
            cout<<val<<" is pushed\n";
            return;
        }
    }
    void pop(){
        if(!isEmpty()){
            cout<<arr[top]<<" is popped\n";
            top--;
            return;
        }
    }




    void peep(){
        if(!isEmpty()){
        cout<<"The top of the array element is: "<<arr[top]<<endl;
        return;
        }
        
    }


    void display(){
        if(isEmpty()){
            cout<<"Array is Empty!!!\n";
            return;
        }
        for(int i = top ; i >=0 ; i--){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    StackArrayReverse stc(5);
    stc.push(1);
    stc.display();
    stc.push(2);
    stc.display();
    stc.push(3);
    stc.display();
    stc.push(4);
    stc.display();
    stc.push(5);
    stc.display();
    cout<<endl;
    cout<<endl;
    stc.pop();
    stc.display();
    stc.pop();
    stc.display();
    stc.pop();
    stc.display();
}