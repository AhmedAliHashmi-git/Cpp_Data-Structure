#include<iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    char *arr;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new char[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(char a)
    {
        if (!isFull())
        {
            top++;
            arr[top] = a;
            cout << "Element: " << a << " is pushed" << endl;
        }
        else
        {
            cout << "Stack is full" << endl;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            char popped = arr[top];
            top--;
            return popped;
        }
        else
        {
            cout << "Stack is empty" << endl;
            return '\0'; 
        }
    }
};

void reverseString(Stack &stack,  string &input)
{
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        stack.push(c);
    }

    cout<<"Reversed String: ";
    while (!stack.isEmpty())
    {
        cout<<stack.pop();
    }
    cout << endl;
}


int main()
{
    Stack stc(5);
    string input = "ahmed";
    reverseString(stc, input);
}
