#include<iostream>
using namespace std;
class array_list{
	int length;
	char *ptr;
	char *curr;
	int size;
	public:
		array_list(int size){
			length=0;
			this->size=size;
			ptr=new char[size];
			curr=ptr;
		}
		void next(){
			curr++;
		}
	void back(){
			curr--;
		}
		
		void start(){
			curr=ptr;
		}
	void tail(){
			curr=ptr+length;
		}
		
void insert(int index, char value) {
if(size==length) {
cout<<"list is full"<<endl;
} 
else if(index<0 || index>length) {
cout<<"invalid position"<<endl;
} 
else {
tail();
for(int i=length; i>=index; i--){	
*(curr+1)=*curr;
back();
}
*(curr+1)=value;
length++;
}
}
		
		void remove(int index){
			
			if(length==size){
				cout<<"Array is completpy filled : "<<endl;
			}
			else  if(index<0||index>length){
				cout<<"Invalid position : "<<endl;
			}
			else
			start();
			for(int i=index;i<length;i++){
				*(curr+i)=*(curr+i+1);
				
			}
			length--;
		}
		
		
void printList() {
    start();
    for (int i = 0; i < length; i++) {
        cout << *curr << " ";
        next(); // Move to the next element
    }
    cout << endl;
}
		
		
		
		
		
};
int main(){
	int choice,index,count=0;
	char value;
	array_list obj1(10);
	obj1.insert(0,'s');
	obj1.insert(1,'r');
	obj1.insert(2,'v');
	obj1.insert(3,'d');
	obj1.insert(4,'m');
	obj1.insert(5,'a');
	obj1.printList();
	
	
	while(true){
	
	
	cout<<"01) Insert "<<endl<<"02) Remove : "<<endl<<"03) Exit : "<<endl;	
	cout<<"Select a option : ";
	cin>>choice;
	if(choice==1){
		cout<<"Enter the index you want to insert : ";
		cin>>index;
		cout<<"Enter a character : ";
		cin>>value;
		obj1.insert(index,value);
		obj1.printList();
		count++;
	}
	else if(choice==2){
		cout<<"Enter the index you want to remove : ";
		cin>>index;
		obj1.remove(index);
		obj1.printList();
	}
   else if(choice!=1&&choice!=2&&choice!=3){
   	cout<<"Select a correct option : "<<endl;
   }
   else if(choice==3){
   	cout<<"You complete your task in "<<count<<" entries ...."<<endl;
	cout<<"See you next time "<<endl;
   	break;
   }
	
}

}