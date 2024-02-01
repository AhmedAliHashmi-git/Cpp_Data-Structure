#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
};

class graph {
    Node* head;

public:
    graph() {
        head = nullptr;
    }

    Node* LL(int dest) {
        Node* temp = new Node;
        temp->data = dest;
        temp->next = nullptr;
        temp->bottom = nullptr;
        return temp;
    }

    void edge(int src, int dest) {
        if (head == nullptr) {
            head = LL(src);
            head->bottom = LL(dest);
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = LL(src);
            temp->next->bottom = LL(dest);
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Node " << temp->data << ": ";
            Node* bottomList = temp->bottom;
            while (bottomList != nullptr) {
                cout << bottomList->data << " ";
                bottomList = bottomList->next;
            }
            cout << endl;
            temp = temp->next;
        }
    }
};

int main() {
    graph g;
    g.edge(1, 2);
    g.edge(1, 5);
    g.edge(1, 9);

    g.edge(3, 4);
    g.edge(5, 6);

    cout << "Graph:" << endl;
    g.print();

    return 0;
}
