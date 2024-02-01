#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
    char val;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = NULL;
    }
};
class Stack
{
    Node *top;
    int limit;
    int length;

public:
    Stack(int limit)
    {
        this->limit = limit;
        top = NULL;
        length = 0;
    }
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
            cout << "Stack is empty" << endl;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (length == limit)
        {
            cout << "Stack is full" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(char val)
    {
        if (!isFull())
        {
            Node *temp = new Node(val);
            temp->next = top;
            top = temp;
            length++;
        }
    }
    char pop()
    {
        Node *temp = top;
        char val = top->val;
        top = top->next;
        delete temp;
        temp = NULL;
        length--;
        return val;
    }
    void peek()
    {
        if (!isEmpty())
        {
            cout << "Top of the stack: " << top->val << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            cout << "Stack Elements : " << endl;
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack a(50);
    Stack b(50);
    char name[100];
    int choice;
    cout << "Enter name: " << endl;
    cin >> name;
    int len = strlen(name);
    for (int i = len; i >= 0; i--)
    {
        a.push(name[i]);
    }

    do
    {
        char val;
        char val1;

        cout << "Enter choice: " << endl;
        cout << "1.Undo" << endl;
        cout << "2.Redo" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            val = a.pop();
            a.display();
            b.push(val);

            break;
        case 2:
            val1 = b.pop();
            a.push(val1);
            a.display();
            break;
        default:
            break;
        }
    } while (choice != 3);
}