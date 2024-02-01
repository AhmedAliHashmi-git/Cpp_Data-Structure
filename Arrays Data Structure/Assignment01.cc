#include<iostream>
using namespace std;
int length(int* ptr , int size){
    int length = 0;
    int* q = ptr;
    for(int i = 0 ; i < size ; i++){
        if(*(ptr + i) != 0){
              length++;
        }
    }
    ptr = q;
    return length;
}


int* add(int* ptr , int  length){
       int num;
       cout<<"Enter the Number you want to add: ";
       cin>>num;
       *(ptr + length ) = num;
       return (ptr + length); 
       
}
int* update(int* ptr, int length) {
    int X, Y;
    cout << "Enter the Number: ";
    cin >> X;
    bool check = true;
    
    for (int i = 0; i < length; i++) {
        if (*(ptr+i) == X) {
            cout << "Enter the new Number: ";
            cin >> Y;
            *(ptr + i) = Y;
            check = false;
            break;
        }
    }
    
    if (check) {
        cout << "Not Found" << endl;
    }
    
    return ptr;
}
int* insect(int* ptr , int length){
    int index , num;
    cout<<"Enter the index: ";
    cin>>index;
    int* q = (ptr + length - 1);
    int *t = ptr;
    if(index <= length && index > 0){
        for(int i = 0 ; i < length+1 ; i++){
        ptr = t;
        
            if(i == index){
            cout<<"Enter the new Number: ";
            cin>>num;
            for(int i = 0 ; i < (length-index) + 1 ; i++){
                *(q + 1) = *q;
                q--;
            }
           *(ptr + index - 1) = num;
           
           break;
            }
            
           ptr++;
        
    }
           
        }
        else{
            cout<<"Invalid Index!!!"<<endl;
            return ptr;
        }

    return ptr;
    
}
int* remove(int* ptr , int& length ){
    int* q = ptr;
    int* store = ptr;
    int num;
    cout<<"Enter the Number you want to delete from the array: ";
    cin>>num;
    bool found = false;
    for(int i = 0 ; i  < length ; i++){
        
        if(i == num){
            int term = *(store + i + 1);
           *(store + i + 1) = *(ptr + i)  ;
           *(ptr + i) = term;
           found = true;
        }
        
    }
    if(!found){
        length++;
    }
    
    return ptr ;
}
int end(int* ptr , int length){
    int index;
    int *q = (ptr + length - 1);
    cout<<"Enter the index you want to be: ";
    cin>>index;
    for(int i = 0 ; i < length ; i++){
        if(index <= length && index > 0){
            if(i == index){
            cout<<"You are currenty in " << i <<" index the value is: "<<*(ptr + i) << endl;
            ptr = q;
        }
        }
        else{
            return 0;
        }
        
    }
    return *ptr;
}
int start(int* ptr , int length){
     int* q = ptr;
     int index;
    cout<<"Enter the index you want to be: ";
    cin>>index;
     for(int i = 0 ; i < length ; i++){
        if(index <= length && index > 0){
            if(i == index){
            cout<<"You are currenty in " << i <<" index the value is: "<<*(ptr + i) << endl;
            ptr = q;
        }
        }
        else{
            return 0;
        }
        
    }
    return *ptr;
}
int next(int* ptr, int length) {
    int index;
    cout << "Enter the index: ";
    cin >> index;

    if (index < length && index >= 0) {
        cout << "Your current value is: " << *(ptr + index) << endl;
        return *(ptr + index + 1);
    }

    return 0;
}

int back(int* ptr, int length) {
    int index;
    cout << "Enter the index: ";
    cin >> index;

    if (index < length && index >= 0) {
        cout << "Your current value is: " << *(ptr + index) << endl;
        return *(ptr + index - 1);
    }

    return 0;
}



int get(int* ptr , int length){
    int index;
    cout<<"Enter the index: ";
    cin>>index;
    for(int i = 0 ; i < length ; i++){
        if(i == index){
            return *ptr;
        }
    }
    return 0;

}


int main(){
    int size = 10;
    int arr[size] = {1 , 6, 3 ,9,8};
    int* node = arr;
    int op;
    cout<<"Enter your choice: ";
    cin>>op;
    int len = length(node , size);
    if(op == 1){
    int len = length(node , size);
    cout<<len;
    }
    else if(op == 2){
        
        int* ptr = add(node , len);
        for(int i = 0 ; i < len + 1 ; i++){
         cout<<*(ptr-len+i) <<" ";
        }

    }
    else if(op == 3){
       
       int* ptr = update(node , len);
       if(ptr != 0){
        for(int i = 0 ; i < len ; i++){
            cout<<*ptr<<" ";
            ptr++;
       }
       }
    }
    else if(op == 4){
        int* ptr = insect(node , len);
        for(int i = 0 ; i < len + 1 ; i++){
            cout<<*ptr<<" ";
            ptr++;
        }
    }
    else if(op == 5){
        int* ptr = remove(node , len );
        
         for(int i = 0 ; i < len -1; i++){
            cout<<*ptr<<" ";
            ptr++;
            
        }
    }
    else if(op == 6){
        int val = end(node , len);
        if(val == 0){
            cout<<"Invalid index!!!";
        }
        else{
        cout<<"Now You are at the end of the array the value is : " <<val<<endl;
        }
    }
    else if(op == 7){
        int val = start(node , len);
        if(val == 0){
            cout<<"Invalid index!!!";
        }
        else{
        cout<<"Now You are at the start of the array the value is : " <<val<<endl;
        }
    
}
    
    else if(op == 8){
         int val = next(node , len); 
         if(val == 0){
            cout<<"Invalid index!!!";
        }
        else{
          cout<<"The Next value is: " <<val<<endl;        } 
        
        
        }
        else if(op == 9){
         int val = back(node , len); 
         if(val == 0){
            cout<<"Invalid index!!!";
        }
        else{
          cout<<"The back value is: " <<val<<endl;        } 
        
        
        }

        else if(op == 10){
            int val = get(node , len); 
         if(val == 0){
            cout<<"Invalid index!!!";
        }
        else{
          cout<<"The value is: " <<val<<endl;
        }


}
}