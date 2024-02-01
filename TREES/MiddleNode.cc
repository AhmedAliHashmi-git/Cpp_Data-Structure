#include <iostream>
using namespace std;
#include <conio.h>
#include <stdlib.h>

struct node

{

int info;

node *left,*right;

};

class bin_search_tree

{

private :

node *temp;

public :
int even;
int odd;
int count;
int count2;
node *root;

int number;

bin_search_tree();

void options();

void b_search_tree(node *);

void in_order(node *);
void middleOrder(node* temp){

    if(count % 2 == 0){
    even =count/2;
}
   if(count % 2 == 1){
     odd = (count - 1)/2;
   }
   count2++;
   if(count2 == even || count2 == odd){
    cout<<"Middle Order: "<<temp->info;
    return;
   }
   
    if(temp->left != nullptr){
        middleOrder(temp->left);
    }

     if(temp->right != nullptr){
        middleOrder(temp->right);
    }
    
  
}

};
int main()

{


char ch;

bin_search_tree obj;

while( 5)

{

obj.options();

ch=getch();

switch(ch)

{

case '1':


cout<<"\n Enter number to add in a tree... \n";

cin>>obj.number;

obj.b_search_tree( obj.root );

break;
case '2':

obj.in_order(obj.root);
cout<<obj.count<<endl;


break;

case '3':

exit(0);

break;
case '4':
obj.middleOrder(obj.root);
break;

default :

exit(0);

break;

} // end of switch.

} // end of while.

}//-----------------------------------------------

bin_search_tree :: bin_search_tree()

{

root=temp=NULL;
count2 = 0;
even =-1;
count = 0;
odd = -1;

}

//--------------------------------------------------------
void bin_search_tree :: b_search_tree(node *temp)

{

if( root==NULL )

{

temp=new node;

temp->info = number;

temp->left=NULL;

temp->right=NULL;

root=temp;

return;

}

if( temp->info==number )

{

cout<<" \n Given number is already present in tree.\n";

return;

}
if(temp->info > number)

{

if( temp->left!=NULL )

{

b_search_tree(temp->left);

return;

}

else

{

temp->left=new node;

temp->left->info = number;

temp->left->left=NULL;

temp->left->right=NULL;

return;

}

}

if(temp->info < number)

{

if( temp->right!=NULL )

{

b_search_tree( temp->right );

return;

}

else

{

temp->right=new node;

temp->right->info = number;

temp->right->left=NULL;

temp->right->right=NULL;

return;

}

}

} //-------------------- Insertion Function Ends --------------------------
void bin_search_tree :: options()

{

cout<<"\n\n ************** Select Option *****************.\n";

cout<<"\n Enter any of choices.\n";

cout<<"\n 1 : Adding (inserting) node in BST.\n";

cout<<"\n 2 : Print the whole BST .\n";

cout<<"\n 3 : Quitting the Program.\n";

}//--------------------------------------------------------------

void bin_search_tree :: in_order(node *temp)

{

if(root==NULL)

{

cout<<" Tree is empty.\n";

return;

}

count++;


if(temp->left != nullptr){
    in_order(temp->left);
}

if(temp->right != nullptr){
    in_order(temp->right);
}


return;

}

//---------------------------- PROGRAM ENDS HERE ---------------------------------------