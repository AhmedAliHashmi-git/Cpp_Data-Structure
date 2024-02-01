#include<iostream>
using namespace std;
class publicationDate{
    public:
    int date;
    int month;
    int year;
};
struct node : public publicationDate{
    node* next;
    node* previous;
    string author;
    string bookTitle;
    string genre;
    int ISBN;

    node(){
        next = nullptr;
        previous = nullptr;
        author = "Not Set";
        bookTitle = "Not Set";
        genre = "Not set";
        ISBN = 0;
    }
};

class Library {
    node* head;

    public:

    Library(){
        head = nullptr;
    }
     void add() {
        node* temp1 = new node;
        cout << "Enter the detail: \n" << "Enter the name of the book:";
        cin >> temp1->bookTitle;
        cout << "Enter the author of the book: ";
        cin >> temp1->author;
        cout << "Enter the genre: ";
        cin >> temp1->genre;
        cout << "Enter ISBN number: ";
        cin >> temp1->ISBN;
        cout << "Enter date:";
        cin >> temp1->date;
        cout << "Enter Month: ";
        cin >> temp1->month;
        cout << "Enter Year: ";
        cin >> temp1->year;

        if (head == nullptr || head->year > temp1->year ||(head->year == temp1->year && head->month > temp1->month) ||(head->year == temp1->year && head->month == temp1->month && head->date > temp1->date)) {
            temp1->next = head;
            temp1->previous = nullptr;
            if (head != nullptr) {
                head->previous = temp1;
            }
            head = temp1;
        } else {
            node* temp = head;
            while (temp->next != nullptr &&
                   (temp->next->year < temp1->year ||(temp->next->year == temp1->year && temp->next->month < temp1->month) ||(temp->next->year == temp1->year && temp->next->month == temp1->month && temp->next->date < temp1->date))) {
                temp = temp->next;
            }
            temp1->next = temp->next;
            temp1->previous = temp;
            if (temp->next != nullptr) {
                temp->next->previous = temp1;
            }
            temp->next = temp1;
        }
    }
        void search(){
            if(head == nullptr){
                cout<<"List is Empty!!!\n";
                return;
            }
            int isbn;
            cout<<"Enter the isbn number you want detail: ";
            cin>>isbn;
            node* temp = head;
            while (temp != nullptr)
            {
                if(isbn == temp->ISBN){
                cout<<"Author of the Book: "<<temp->author<<endl;
                cout<<"Title of the Book: "<<temp->bookTitle<<endl;
                cout<<"Genre of the Book: "<<temp->genre<<endl;
                cout<<"ISBN number: "<<temp->ISBN<<endl;
                cout<<endl<<endl<<"Dated: "<<temp->date<<"/"<<temp->month<<"/"<<temp->year<<endl<<endl;
                return;
                }
                temp = temp->next;
            }
            cout<<"Book not Found in the List!!!"<<endl;
            return;
            
        }
        void filterBook(){
            if(head == nullptr){
                cout<<"List is Empty!!!\n";
                return;
            }
            bool found  = false;
            string authorName; 
            cout<<"Enter name of authore: ";
            cin>>authorName;
            node* temp = head;
            while(temp != nullptr){
                if(authorName == temp->author){
                    cout<<"-"<<temp->bookTitle<<endl;
                    found = true;
                }temp = temp->next;
            }
            if(!found){
                cout<<endl<<"Authore have'nt written any book!!!\n";
            }   
            
            cout<<endl;
        }

        void relatedBook(){
             if(head == nullptr){
                cout<<"List is Empty!!!\n";
                return;
             }
             node* temp = head;
             string name;
             cout<<"Enter the title of the book: ";
             cin>>name;
             string genre;
             
             while(temp != nullptr){
                if(name == temp->bookTitle)
                {
                    genre = temp->genre;
                    break;
                }temp = temp->next;
             }
             int  count = 0;
             bool found = false;
             bool check = false;
             while(temp != nullptr && count != 4){
                if(genre == temp->genre){
                if (check) {
                cout << "-" << temp->bookTitle << endl;
                count++;
            } else {
                check = true; 
            }
                    found = true;
                } 
                temp = temp->next;
             }
             if(!found){
                cout<<endl<<"Authore have'nt written any book!!!\n";
            } 
        }

         void remove(){
             if(head == nullptr){
                cout<<"List is Empty!!!\n";
                return;
             }
             int isbn;
             bool found = false;
             cout<<"Enter isbn number: ";
             cin>>isbn;
    
           node* temp = head;
           while(temp != NULL){
            if(isbn == temp->ISBN){
            node* temp1 = temp;
            if( temp->previous != NULL){
                temp->previous->next = temp->next;
            }
            if(temp->next != NULL){
            temp->next->previous = temp->previous;
            }
            if(head == temp){
                head = temp->next;
            }
            delete temp;
            found = true;
            return;
            }
            
           
            temp = temp->next;
           
        }
    if(!found){
        cout<<"Not found!!!\n";
    }
         }

        void display(){
            if(head == nullptr){
                cout<<"List is Empty!!!\n";
                return;
            }
            node* temp = head;
            while(temp != nullptr){
                cout<<endl;
                cout<<"Author of the Book: "<<temp->author<<endl;
                cout<<"Title of the Book: "<<temp->bookTitle<<endl;
                cout<<"Genre of the Book: "<<temp->genre<<endl;
                cout<<"ISBN number: "<<temp->ISBN<<endl;
                cout<<"Dated: "<<temp->date<<"/"<<temp->month<<"/"<<temp->year<<endl;
                temp = temp->next;
            }cout<<endl;
        }

    

};
void menu(){
    int choice;
    Library lib;
    while(true){
        cout<<"Enter your option: \n1- Add a New Book\n2- Search For a Book\n3- Display Book\n4- Filter Books by Author\n5- Recommend Related Books\n6- Delete a book\n7- Quit\n\n\n";
        cin>>choice;
        if(choice == 1){
            lib.add();
        }
        else if(choice == 2){
            lib.search();
        }
        else if(choice == 3){
           lib. display();
        }
        else if(choice == 4){
            lib.filterBook();
        }
        else if(choice == 5){
            lib.relatedBook();
        }
        else if(choice == 6){
            lib.remove();
        }
        else if(choice == 7){
            break;
        }
    }
}




int main(){
    menu();
}
