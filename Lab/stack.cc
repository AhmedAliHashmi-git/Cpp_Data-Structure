#include<iostream>
using namespace std;
class Node
{
public:
int val;
Node *next;
Node(int val)
{
this->val=val;
next=NULL;
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
this->limit=limit;
top=NULL;
length=0;
}
~Stack() {
while (!isEmpty()) {
pop();
}
}
bool isEmpty()
{
if(top==NULL)
{
return true;
cout<<"Stack is empty"<<endl;
}
else
{
return false;
}
}
bool isFull()
{
if(length==limit)
{
cout<<"Stack is full"<<endl;
return true;
}
else
{
return false;
}
}
void push(int val)
{
if(!isFull())
{
Node *temp=new Node(val);
temp->next=top;
top=temp;
length++;
cout<<"Element: "<<val<<"is pushed"<<endl;
}
}
void pop()
{
Node *temp=top;
int val=top->val;
top=top->next;
delete temp;
temp=NULL;
length--;
cout<<"Element: "<<val<<" is popped"<<endl;
}
void peek()
{
if(!isEmpty())
{
cout<<"Top of the stack: "<<top->val<<endl;
}
}
void display()
{
if(!isEmpty())
{
cout<<"Stack Elements: "<<endl;
Node *temp=top;
while(temp!=NULL)
{
cout<<temp->val<<endl;
temp=temp->next;
}
cout<<endl;
}
}
};
int main()
{
Stack s(5);
s.push(2);
s.display();
s.push(3);
s.display();
s.push(4);
s.display();
s.pop();
s.display();
s.push(8);
s.display();
s.peek();
}