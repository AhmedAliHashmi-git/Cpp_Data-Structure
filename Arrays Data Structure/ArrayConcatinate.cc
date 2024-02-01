#include <iostream>
#include <string>
using namespace std;
void string4(char* q , int size){
    char* p = q;
       for (int i = 0; i < size - 1; i++) {
        cout << "Enter character: ";
        cin >> *q;
        q++;
    }*q = '\0';
       while(*q != '\0'){
        cout<<*q;
        q++;
       }
}
int main() {
    char xyz[5];
    string4(xyz , 5); 
}
