#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
  srand(time(0));
   int arr[3][3];
   int* ptr = &arr[0][0];
   for(int i = 0 ; i < 3 ; i++){
    for(int j= 0 ; j< 3 ; j++){
      int random = rand()%10 + 1;
      if(i == 1 && j == 1){
        cout<<'O'<<" ";
      }
      else if(random >= 1 && random <= 5){
        arr[i][j] = '-';
        cout<<'-'<<" ";
      }
      else {
        arr[i][j] = 'X';
        cout<<'X'<<" ";
      }
    }cout<<endl;
   }
   ptr = &arr[1][1];
   int op;
   cout<<"1- Right\n2- Left\n3- Top\n4- Bottom.\n";
   cin>>op;
   if(op == 1){
    ptr++;
    if(*ptr == '-'){
      cout<<"You Won";
    }

    else if(*ptr == 'X'){
      cout<<"You loss";
    }
    ptr--;
   }

   else if(op == 2){
    ptr--;
    if(*ptr == '-'){
      cout<<"You Won";
    }

    else if(*ptr == 'X'){
      cout<<"You loss";
    }
    ptr++;
   }

   else if(op == 3){
    ptr-=3;
    if(*ptr == '-'){
      cout<<"You Won";
    }

    else if(*ptr == 'X'){
      cout<<"You loss";
    }
    ptr+=3;
   } 

   else if(op == 4){
    ptr+=3;
    if(*ptr == '-'){
      cout<<"You Won";
    }

    else if(*ptr == 'X'){
      cout<<"You loss";
    }
    ptr-=3;
   } 

}