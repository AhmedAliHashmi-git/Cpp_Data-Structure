#include<iostream>
using namespace std;

struct node{
    string name;
    string rollNo;
    float gpa;  
    node* next;
    node():name("\0") , rollNo("\0"),gpa(0.0),next(nullptr){}
};


class StudentList{
    public:
    node* head;
    
    StudentList():head(nullptr){}

    void add(){
        
        if(head == nullptr){
        head = new node;
        cout<<"Enter Name of the Student: ";
        cin>>head->name;
        cout<<"Enter roll Number of the Student: ";
        cin>>head->rollNo;
        cout<<"Enter gpa of the student: ";
        cin>>head->gpa;
        head->next = nullptr;
        return;
        }
    }
    void display(){
        node* temp = head;
        while (temp != nullptr) {
            cout <<"Name- "<< temp->name << endl<<"Roll No- " << temp->rollNo << endl <<"Gpa- "<< temp->gpa << endl<<endl;
            temp = temp->next;
        }
    }


   
};

int main(){
    StudentList s;
    s.add();
    s.display();
}