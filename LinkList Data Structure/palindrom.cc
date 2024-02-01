#include<iostream>
using namespace std;
class Array{
   int* ptr;
   int* q;
   int size;
   int length;
   public:
   Array(int size) : size(size){
     ptr = new int[size];
     q = ptr;
   }
   void add(int val, int pos) {
    if (length == size) {
        cout << "Array is full!!!" << endl;
        return;
    }
    if (pos < 1 || pos > length + 1) {
        cout << "Invalid Index!!!" << endl;
        return;
    }

    q = ptr;
    for (int i = length; i >= pos; i--) {
        *(q + i) = *(q + i - 1);
    }
    *(q + pos - 1) = val; 
    length++;
}

   void print() {
        q = ptr;
        for (int i = 0; i < length; i++) {
            cout << *q << " ";
            q++;
        }
        int* start = ptr;
        int* end = ptr + length - 1;
        bool check = false;
        while(start < end){
            if(*start != *end){
                check = true;
                break;
            }
            start++;
            end--;
        }
        if(!check)
        {
            cout<<"Palindrome Number";
        }
        else{
            cout<<"Not a Palindrome Number";
        }

    }

}; 
int main(){
    Array arr(10);
    arr.add(9 , 1);
    arr.add(5 , 2);
    arr.add(3 , 3);
    arr.add(5 , 4);
    arr.add(7 , 5);
    arr.print();

}