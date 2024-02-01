#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* previous;
    Node() {
        next = nullptr;
        previous = nullptr;
    }
};

class DLL {
    Node* head;
    int top;
    int* arr;
public:
    int size;
    DLL();
    ~DLL();
    void print();
    void insert(int val);
    void reverse(int k);
    void push(int word);
    int pop();
    bool isEmpty();
    bool isFull();
};

DLL::DLL() {
    head = nullptr;
    top = -1;
    size = 0;
    arr = nullptr;
}
DLL :: ~DLL(){
    delete head;
} 

bool DLL::isEmpty() {
    return top == -1;
}

bool DLL::isFull() {
    return top == size - 1;
}

void DLL::insert(int val) {
    if (head == nullptr) {
        head = new Node;
        head->info = val;
        size++;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        Node* temp1 = new Node;
        temp1->info = val;
        temp->next = temp1;
        temp1->previous = temp;
        size++;
    }
}

void DLL::print() {
    if (head == nullptr) {
        cout << "List is Empty!!!!\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DLL::reverse(int k) {
    if (k <= 1) {
        return;
    }

    Node* temp = head;
    Node* prev_tail = nullptr;

    while (temp != nullptr) {
        Node* current_head = temp;
        Node* prev = nullptr;
        int count = 0;

        int* stack = new int[k];
        int stackTop = -1;

        while (temp != nullptr && count < k) {
            stackTop++;
            stack[stackTop] = temp->info;

            Node* next = temp->next;
            temp = next;
            count++;
        }

        while (stackTop >= 0) {
            if (prev_tail != nullptr) {
                prev_tail->next = new Node;
                prev_tail->next->info = stack[stackTop];
                prev_tail->next->previous = prev_tail;
                prev_tail = prev_tail->next;
            } else {
                head = new Node();
                head->info = stack[stackTop];
                head->previous = nullptr;
                prev_tail = head;
            }
            stackTop--;
        }

        current_head->next = temp;
        if (temp != nullptr) {
            temp->previous = current_head;
        }

        delete[] stack;
    }
}


void DLL::push(int word) {
    if (!isFull()) {
        top++;
        arr[top] = word;
    }
}

int DLL::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty!!!\n";
        return 0;
    }
    int popped = arr[top];
    top--;
    return popped;
}

int main() {
    DLL dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    dll.insert(6);
    dll.insert(7);
    dll.insert(8);
    dll.insert(9);
    cout<<"Before Reverse: \n";
    dll.print();
    int K;
    cout << "Enter K: ";
    cin >> K;

    if (dll.size % K != 0) {
        cout << "Number of elements is not a multiple of K." << endl;
        return 0;
    }

    dll.reverse(K);
    cout<<"After Reverse: \n";
    dll.print();
}
