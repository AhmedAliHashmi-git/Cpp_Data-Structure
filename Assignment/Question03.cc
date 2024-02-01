#include<iostream>
using namespace std;
struct Node{
    string name;
    int merit;
    Node* next;

    Node(){
        next = nullptr;
    }
};

class Student{
    Node* front;
    Node* rear;
    public:
    
    Student(){
        rear = front = nullptr;
    }
    int size(){
        int count = 0;
        Node* temp = front;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void enqueue(){
        string name;
        int merit;
        cout<<"Enter Name of the student: ";
        cin>>name;
        cout<<"Enter the merit position: ";
        cin>>merit;
        
        if(rear == nullptr){
            rear = new Node; 
            rear->name = name;
            rear->merit = merit;
            front = rear;
            rear->next = nullptr;
            return;
        }
        rear->next = new Node;
        rear = rear->next;
        rear->name = name;
        rear->merit = merit;

        rear->next = nullptr;
        return;
    }

    void display(){
        if(front == nullptr){
            cout<<"No One in the Queue\n";
            return;
        }
        int i = 1;
        Node* temp = front;
        while(temp != nullptr){
           cout<<i<<"-"<<temp->name<<endl;
           temp = temp->next;
           i++;
        }
    }

    string nextPerson(){
        return front->name;
    }

     void dequeue(){
        if(front == nullptr){
            cout<<"There is no one left!!!!\n";
            return;
        }
        Node* temp = front;
            if(temp->merit < 50){
              cout<<"Bad Luck ";
              cout<<front->name<<"-Not selected\n";

            }
        else{
            cout<<"Congratulation ";
            cout<<front->name<<"-selected\n";
        }
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        return;
        
     }
};
int main(){
    Student stu1 , stu2 , stu3;
    int totalCount = 0;
    int choice;
    while(true){
        cout<<"Enter the Choice:\n1-Add Student in a Queue\n2-Process Admissions\n3-Check Queue status\n4-See who is next\n5-Exit\n\n  ";
        cin>>choice;
        int size1 = stu1.size();    
        int size2 = stu2.size();
        int size3 = stu3.size();
        if(choice == 1){
            if(size1 <= size2 &&  size1 <= size3){
            totalCount++;
            stu1.enqueue();
        }
        else if(size2 <= size1 &&  size2 <= size3){
            totalCount++;
            stu2.enqueue();
        }
        else if(size3 <= size1 &&  size3 <= size1){
            totalCount++;
            stu3.enqueue();
        }
        }
        else if(choice == 3){
            cout<<"Queue 01:\n";
            stu1.display();
            cout<<"Queue 02:\n";
            stu2.display();
            cout<<"Queue 03:\n";
            stu3.display();
        }
       else if (choice == 2) {
    while (totalCount > 0) {
        int minSize = INT_MAX;

        if (size1 > 0 && size1 < minSize) {
            minSize = size1;
        }
        if (size2 > 0 && size2 < minSize) {
            minSize = size2;
        }
        if (size3 > 0 && size3 < minSize) {
            minSize = size3;
        }

        if (size1 == minSize && size1 > 0) {
            stu1.dequeue();
            size1--;
            totalCount--;
        } else if (size2 == minSize && size2 > 0) {
            stu2.dequeue();
            size2--;
            totalCount--;
        } else if (size3 == minSize && size3 > 0) {
            stu3.dequeue();
            size3--;
            totalCount--;
        }
    }
}




        
        else if(choice == 4){
            int op;
            cout<<"Enter the Queue 1,2,3: ";
            cin>>op;
            if(op == 1){
               cout<<stu1.nextPerson() <<" is waiting\n";
            }
            if(op == 2){
                cout<<stu2.nextPerson()<<" is waiting\n";
            }
            if(op == 3){
                cout<<stu3.nextPerson()<<" is waiting\n";
            }
        }
        else if(choice == 5){
            break;
        }
        
    }
}

