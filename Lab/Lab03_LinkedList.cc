#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* next = NULL;
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() {
        length = 0;
        head = NULL;
    }

    void add(int pos) {
        cout << "Enter a Song: ";
        string song_name;
        cin >> song_name;

        if (pos < 1 || pos > (length + 1)) {
            cout << "Invalid position" << endl;
            return;
        }
        else if (pos == 1) {
            Node* temp = new Node;
            temp->song = song_name;
            temp->next = head;
            head = temp;
        }
        else { 
            Node* curr = head;
            for (int i = 1; i < (pos - 1); i++) {
                curr = curr->next;
            }
            Node* temp = new Node;
            temp->song = song_name;
            temp->next = curr->next;
            curr->next = temp;
        }
        length++;
    }
    void remove(){
    Node* temp = head;
    string song;
    bool found=false;
    cout<<"Enter the song you want to delete: ";
    cin>>song;
    if(temp == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }
    if (temp != NULL && temp->song == song) {
        head = temp->next; 
        delete temp; 
        return;
    }
    
    while(temp != NULL){
        if(temp->next != NULL && temp->next->song == song){
            Node* temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;
            found = true;
        }
        temp = temp->next;
    }
    if(!found){
        cout<<"Item did'nt found"<<endl;
    }
}
    void printList() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->song << " ";
            curr = curr->next;
            cout << endl;
        }
        
    }
    void search(){
        string song;
        cout<<"Enter a Song you want to search: ";
        cin>>song;
        Node* temp = head;
        bool found = false;
        while(temp != NULL){
            if(temp->song == song){
                cout<<"This Song Exist"<<endl;
                found = true;
            } 
            temp = temp->next;
        }
        if(!found){
            cout<<"Do not find a song Found "<<endl;
        }
    }
    void playSong() {
    string song;
    int op;
    cout << "Enter a Song you want to search: ";
    cin >> song;
    Node* temp = head;
    Node* curr = NULL;
    bool found = false;

    while (temp != NULL) {
        if (temp->song == song) {
            cout << "Now Playing...." << endl;
            cout << temp->song << endl;

            while (true) {
                cout << "You want to play the next song:\n1). Yes\n2). No\n";
                cin >> op;

                if (op == 1) {
                    if (curr == NULL) {
                        curr = temp; 
                    }

                    if (curr->next != NULL) {
                        curr = curr->next; 
                        cout << "Now Playing...." << endl;
                        cout << curr->song << endl;
                    } else {
                        cout << "End of the playlist." << endl;
                        return;
                    }
                } else if (op == 2) {
                    return;
                } else {
                    cout << "Invalid option. Please enter 1 or 2." << endl;
                }
            }
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Song not found in the playlist." << endl;
    }
}


};

int main() {
    int op;
    LinkedList LL;
    while(true){
        cout << "Select an Option\n1). Add a Song\n2). Delete a Song\n3). Print Playlist\n4). Search a Song\n5). Start Playlist\n6). Exit\n";
    cin >> op;
    if (op == 1) {
        int pos;
        cout<<"Enter a postion you want to enter a Song: ";
        cin>>pos;
        LL.add(pos);
        LL.printList();
    }
    else if(op == 2){
        LL.remove();
        LL.printList();
    }
    else if(op == 3){
        LL.printList();
    }
    else if(op == 4){
        LL.search();
    }
    else if(op == 5){
        LL.playSong();
    }
    else if(op == 6){
        break;
    }
    
    }
    
}
