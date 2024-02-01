#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter key: ";
    cin>>size;
    char* ptr = new char[size];
    char* ptr2 = new char[size];
    char* temp = ptr;
    for(int i = 0 ; i < size ; i++){
        temp = ptr++;
    }
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the name: ";
        cin>>*(ptr+i);
    }
    cout<<endl<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter the name: ";
        cin>>*(ptr2+i);
    }
    bool check = false;

    while(*ptr2 != '\0' && *temp != '\0'){
        if(*ptr2 != *temp){
            check = false;
            break;
        }
        ptr2++;
        temp--;
    }
    if(!check){
        cout<<" same\n";
    }
    else {
        cout<<"Not same\n";
            }

}