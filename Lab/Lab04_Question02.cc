#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node( string& s) : song(s), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    int length;

public:
    CircularLinkedList() {
        length = 0;
        head = nullptr;
    }

    ~CircularLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add( string& song_name, int pos) {
        if (pos < 1 || pos > (length + 1)) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newSong = new Node(song_name);

        if (head == nullptr) {
            head = newSong;
            head->next = head; 
        } else if (pos == 1) {
            newSong->next = head->next;
            head->next = newSong;
        } else {
            Node* curr = head;
            for (int i = 1; i < (pos - 1); i++) {
                curr = curr->next;
            }
            newSong->next = curr->next;
            curr->next = newSong;
        }
        length++;
    }

    void remove(const string& song_name) {
    if (head == nullptr) {
        cout << "List is Empty" << endl;
        return;
    }

    Node* temp = head;
    bool found = false;

    if (temp != nullptr && temp->song == song_name) {
        if (temp->next == head) {
            head->next = head;
        } else {
            head = temp->next;
            Node* last = head;
            while (last->next != temp) {
                last = last->next;
            }
            last->next = head;
        }
        delete temp;
        length--;
        found = true;
    } else {
        do {
            if (temp->next != nullptr && temp->next->song == song_name) {
                Node* temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
                length--;
                found = true;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }

    if (!found) {
        cout << "Song not found in the playlist" << endl;
    }
}


    void printList() {
        if (head == nullptr) {
            cout << "List is Empty" << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->song << endl;
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }

    void search() {
        string song;
        cout << "Enter a Song you want to search: ";
        cin >> song;
        Node* temp = head;
        bool found = false;
        do {
            if (temp->song == song) {
                cout << "This Song Exists" << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }while (temp != head);

        if (!found) {
            cout << "Song not found in the playlist" << endl;
        }
    }

    void playSong() {
        if (head == nullptr) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << "Now Playing: " << curr->song << endl;
            cout << "Play next song? \n1).Yes\n2).No: \n";
            int choice;
            cin >> choice;

            if (choice == 2) {
                break;
            }


            curr = curr->next;
        } while (curr != head);
    }
};

int main() {
    int op;
    CircularLinkedList playlist;
    while (true) {
        cout << "Select an Option\n1). Add a Song\n2). Delete a Song\n3). Print Playlist\n4). Search a Song\n5). Start Playlist\n6). Exit\n";
        cin >> op;
        if (op == 1) {
            string song_name; 
            int pos;
            cout << "Enter a position you want to enter a Song: ";
            cin >> pos;
            cout << "Enter the song name: ";
            cin >> song_name;
            playlist.add(song_name, pos);
        } else if (op == 2) {
            string song_name; 
            cout << "Enter the song name you want to delete: ";
            cin >> song_name;
            playlist.remove(song_name);
        } else if (op == 3) {
            playlist.printList();
        } else if (op == 4) {
            playlist.search();
        } else if (op == 5) {
            playlist.playSong();
        } else if (op == 6) {
            break;
        }
    }
}
