#include<iostream>
using namespace std;
struct Node{
    Node* next;
    int info;
    Node(){
        next = nullptr;
    }
};

class Queue{
     Node* front;
     Node* rear;
     Node* temp;
     int limit;
     int length;
     public:

     Queue(int limit) : limit(limit){
        front = rear = temp = nullptr;
        length = 0;
     }

     void Enqueue(){
        if(rear == nullptr){
            rear = new Node;
            cout<<"Enter a value: ";
            cin>>rear->info;
            front = rear;
            rear->next = nullptr;
            length++;
            return;
        }
        if(length == limit){
            cout<<"Limit has Exeded!!!\n";
            return;
        }
        //......One Way
        // Node* temp = new Node;
        // cout<<"Enter the new value: ";
        // cin>>temp->info;
        // temp->next = nullptr;
        // rear->next = temp;
        // rear = temp;
 
        //......2nd way
        rear->next = new Node;
        rear = rear->next;
        cout<<"Enter the new Value: ";
        cin>>rear->info;
        rear->next = nullptr;
        length++;
        return;
     }

     void Dequeue(){
        if(front == nullptr){
            cout<<"Queue is Empty!!!\n";
            return;
        }
        temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        length--;
        delete temp;
        return;
     }
     void print(){
        if(rear == NULL){
            cout<<"Queue is Empty!!!\n";
            return;
        }
        temp = front;
        while(temp!=nullptr){
            cout<<temp->info<<" ";
            temp = temp->next;
        }
     }
};
int main(){
    Queue que(50);
    que.Enqueue();
    que.Enqueue();
    que.Enqueue();
    que.Enqueue();
    que.Enqueue();
    que.Enqueue();
    que.Enqueue();
    que.print();


    cout<<endl<<endl<<endl;
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();
    que.print();
}
