#include<iostream>
using namespace std;
class Queue{
    private:
    int front;
    int rear;
    string* patient;
    int limit;
    public:

    Queue(int limit);
    ~Queue();

    bool isFull();
    bool isEmpty();
    void patientEntry();
    void checkUp();
    void nextPatient();


};
Queue :: Queue(int limit) : limit(limit){
        patient = new string[limit];
        front = -1;
        rear = -1;
}
Queue :: ~Queue(){
    delete[] patient;
}

bool Queue ::  isFull(){
      if(((rear + 1) % limit) == front){
        return true;
      }
      return false;
}

bool Queue ::  isEmpty(){
       if(front == -1 && rear == -1){
        return true;

}
       return false;
}
void Queue :: patientEntry(){
    string name;
    cout<<"Enter the name of the patient: ";
    cin>>name;
      if(isFull()){
        cout<<"Queue is Full.\n";
        return;
      }
      else if(isEmpty()){
        front = 0;
        rear = 0;
      }else {
        rear = ((rear+1) % limit);
      }
      patient[rear] = name;
      cout<<"Patient "<<name<<" now waiting in queue.\n";
      return;
    
  
}
void Queue :: checkUp(){
    if(!isEmpty()){
        string name = patient[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % limit;
        }
        cout<<"Patient "<<name<<" is now with the doctor.\n";
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
}

void Queue :: nextPatient(){
        string name = patient[front];
        cout<<"Next Patient in queue: "<<name<<endl;
}



int main(){
    int size;
    int choice;
    cout<<"Enter the number of seats in the waiting area: ";
    cin>>size;
    Queue q(size);
    while(true){
        cout<<"Enter an option:\n1. Enter a patient in wating queue.\n2. Send next patient to the doctor.\n3. See who is next.\n";
        cin>>choice;
        if(choice == 1){
            q.patientEntry();
        }
        else if(choice == 2){
            q.checkUp();
        }
        else if(choice == 3){
            q.nextPatient();
        }
    }
}

