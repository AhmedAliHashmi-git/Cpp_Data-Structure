#include<iostream>
using namespace std;
class Array{
    int* ptr1;
    int* ptr2;
    int* p;
    int* q;
    int length1;
    int length2;
    int size;

    public:

    Array(int size ): size(size){
        length1 = 0;
        length2 = 0;
        ptr1 = new int[size];
        ptr2 = new int[size];
    }
    void last1(){
        p = ptr1 + length1 - 1;
    }
    void last2(){
        q = ptr2 + length2 - 1;
    }
    void start1(){
        p = ptr1;
    }
    void start2(){
        q = ptr2;
    }

    void add1(int val , int pos){
        if(length1 == size){
           cout<<"Array full\n";
           return;
        }
        if(pos < 0 || pos > length1 + 1){

            cout<<"Invalid index\n";
            return;
        }
        start1();
        for(int i = length1 ; i > pos ; i-- ){
            *(p + i) = *(p + i -1);
        }
        *(p + pos - 1) = val;
        length1++;
    }

    
    void add2(int val , int pos){
        if(length2 == size){
           cout<<"Array full\n";
           return;
        }
        if(pos < 0 || pos > length2 + 1){

            cout<<"Invalid index\n";
            return;
        }
        start2();
        for(int i = length2 ; i > pos ; i-- ){
            *(q + i) = *(q + i -1);
        }
        *(q + pos - 1) = val;
        length2++;
    }
    
    void print() {
        p = ptr1;
        for (int i = 0; i < length1; i++) {
            cout << *p << " ";
            p++;
        }

     cout<<endl<<endl;

}
    void print2() {
        q = ptr2;;
        for (int i = 0; i < length2; i++) {
            cout << *q<< " ";
            q++;
        }

     cout<<endl<<endl;

}

     bool isEqual(){
        if(length1 != length2){
            return false;
        }
        start1();
        start2();
        for(int i = 0 ; i < length1 ; i++){
            if(*p != *q){
                return false;
            }
            p++;
            q++;
        }
        return true;
     }

    
};
int main(){
    Array arr(10);
    arr.add1(1, 1);
    arr.add1(2, 2);
    arr.add1(3, 3);
    arr.add1(4, 4);
    arr.add1(5, 5);
    arr.add1(6, 6);
    arr.print();
    cout<<endl << endl;

    arr.add2(1, 1);
    arr.add2(2, 2);
    arr.add2(4, 3);
    arr.add2(4, 4);
    arr.add2(5, 5);
    arr.add2(6, 6);
    arr.print2();
    if (arr.isEqual()) {
        cout << "Both arrays have equal elements." << endl;
    } else {
        cout << "Arrays have different elements." << endl;
    }
}