#include<iostream>
using namespace std;
struct Node {
    int info;
    Node* next;
};

class Stack {
    Node* top;
    int limit;
    int length;

public:
    Stack(int limit) : limit(limit), top(nullptr), length(0) {}

    void push(int val){
        if (length == limit) {
            cout << "Stack is full!!!" << endl;
            return;
        }
        Node* temp = new Node;
        temp->info = val;
        temp->next = top;
        top = temp;
        length++;
        
    }

    int pop() {
        if (top != NULL) {
            Node* temp = top;
            int a = temp->info;
            top = top->next;
            delete temp;

            length--;
            return a;
        }
        else {
            cout << "Stack is empty!!!" << endl;
        }
        return 0;
    }


};

int main() {
    Stack stc(2);
    int a = 1;
    int b = 2;
    cout<<"Before swapping: \n";
    stc.push(a);
    stc.push(b);
    cout<<a<<" "<<b<<endl; 
    cout<<endl;
    cout<<endl;
     a = stc.pop();
     b = stc.pop();
    cout<<a<<" "<<b<<endl; 


}
