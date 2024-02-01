#include<iostream>
using namespace std;
class QueueWithArray{
        private:
        int* arr;
        int length;
        int limit;

        public:
        QueueWithArray(int limit) : limit(limit){
            arr = new int[limit];
            length = 0;
        }
        ~QueueWithArray(){
            delete[] arr;
        }
        bool isEmpty();
        bool isFull();
        void Enqueue();
        void Dequeue();
        void display();
};


bool QueueWithArray ::  isEmpty(){
    if(length == 0){
        cout<<"Queue is Empty!!!\n";
        return true;
    }
    return false;

}
bool QueueWithArray ::  isFull(){
    if(length >= limit){
        cout<<"Queue is Full!!!\n";
        return true;
    }
    return false;
}



void QueueWithArray ::  Enqueue(){
     if(!isFull()){
        length++;
        int val;
        cout<<"Enter a Value: ";
        cin>>val;
        *(arr + length - 1) = val;
        return;
     }
}

void QueueWithArray :: Dequeue(){
    int* q = arr;
    if(!isEmpty()){
      for(int i = 0 ; i < length  ; i++){
        *(arr + *q) = *(arr + *q + 1);
        q++;
      }length--;
    }
    
}

void QueueWithArray ::  display(){
    if(isEmpty()){
      cout<<"Queue is Empty!!!\n";
      return;
    }
    int* q = arr;
    for(int i = 0 ; i < length ; i++){
       cout<<*q<<" ";
       q++;
    }cout<<endl;
}







int main(){
    QueueWithArray qwa(10);
    qwa.Enqueue();
    qwa.display();
    qwa.Enqueue();
    qwa.display();
    qwa.Enqueue();
    qwa.display();
    qwa.Enqueue();
    qwa.display();
    qwa.Enqueue();
    qwa.display();
    cout<<endl<<endl;
    qwa.Dequeue();
    qwa.display();
    qwa.Dequeue();
    qwa.display();
    qwa.Dequeue();
    qwa.display();
    qwa.Dequeue();
    qwa.display();
    


}

