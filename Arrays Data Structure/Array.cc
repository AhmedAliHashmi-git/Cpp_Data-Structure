#include<iostream>
using namespace std;

class Array {
private:

    int* ptr;
    int* qtr;
    int size;
    int length;

public:
    Array(int size) : size(size), length(0) {
        ptr = new int[size];
        qtr = ptr;
    }

    void addIndex(int index, int val) {
        if (length == size) {
            cout << "Array is full!!!" << endl;
            return;
        }
        if (index < 0 || index > length) {
            cout << "Invalid Index!!!" << endl;
            return;
        }
        qtr = ptr;
        for (int i = length; i > index; i--) {
            *(qtr + i) = *(qtr + i - 1);
        }
        *(qtr + index) = val;
        length++;
        
    }
    void remove(int index){
        if (length == size) {
            cout << "Array is full!!!" << endl;
            return;
        }
        if (index < 0 || index > length) {
            cout << "Invalid Index!!!" << endl;
            return;
        }
        qtr  = ptr;
        for(int i = index ; i < length ; i++){
            *(qtr + i) = *(qtr + i + 1);
        }
        length--;

    }

    void print() {
        qtr = ptr;
        for (int i = 0; i < length; i++) {
            cout << *qtr << " ";
            qtr++;
        }
        cout << endl;
    }

    ~Array() {
        delete[] ptr;
    }
};

int main() {
    Array arr(10);
    arr.addIndex(0, 1);
    arr.print();
    arr.addIndex(1, 3);
    arr.print();
    arr.addIndex(1, 2);
    arr.print();
    arr.addIndex(2, 4);
    arr.print();
    arr.addIndex(0, 5);
    arr.print();
    arr.addIndex(5, 6);
    arr.print();
    cout<<"After remove:\n";
    arr.remove(1);
    arr.print();

    return 0;
}
