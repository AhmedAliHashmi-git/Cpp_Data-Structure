#include <iostream>
#include <vector>//..i have use different funtion of vector
#include <stack>
using namespace std;

class Queue {
public:
    vector<string> items;

    bool is_empty() {
        return items.empty();
    }

    void enqueue(string item) {
        items.push_back(item);
    }

    string dequeue() {
        if (!is_empty()) {
             string front = items.front();
            items.erase(items.begin());
            return front;
        } else {
            return "";
        }
    }

    int size() {
        return items.size();
    }
};

class Stack {
public:
    vector<string> items;

    bool is_empty() {
        return items.empty();
    }

    void push(string item) {
        items.push_back(item);
    }

    string pop() {
        if (!is_empty()) {
            string top = items.back();
            items.pop_back();
            return top;
        } else {
            return "";
        }
    }

    int size() {
        return items.size();
    }
};

void explore_mansion(Queue queue, Stack stack) {
    while (!queue.is_empty()) {
        string currentPlace = queue.dequeue();
        cout<<"You are exploring "<< currentPlace << "." << endl;

        if (rand() % 100 +  30) {
            cout << "Oh no! You encountered a ghost in " << currentPlace<<"!"<<endl;
            stack.push(currentPlace);
        }
    }

    cout << "You left the mansion safe and sound!" <<endl;

    if (!stack.is_empty()) {
        cout << "\nRecent ghost encounters:" <<endl;
        while (!stack.is_empty()) {
            cout << stack.pop() <<endl;
        }
    }
}

int main() {
    Queue mansion_queue;
    mansion_queue.enqueue("The Gateway to Darkness");
    mansion_queue.enqueue("The Creeping Corridor");
    mansion_queue.enqueue("The abandoned lounge");
    mansion_queue.enqueue("The haunted gallery");
    mansion_queue.enqueue("The shadowed library");
    mansion_queue.enqueue("The broken window (the exit)");

    Stack recent_ghost_encounters_stack;

    explore_mansion(mansion_queue, recent_ghost_encounters_stack);

    return 0;
}