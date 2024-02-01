#include <iostream>
using namespace std;

struct Move {
    int disk;
    char source;
    char destination;
    Move() {}
    Move(int disk, char source, char destination) : disk(disk), source(source), destination(destination) {}
};

class Stack {
private:
    static const int MAX_DISKS = 10;
    Move arr[MAX_DISKS];
    int top;

public:
    Stack(){
        top = -1;
    }

    void push(const Move &move) {
        if (top < MAX_DISKS - 1) {
            arr[++top] = move;
        }
    }

    Move pop() {
        Move temp(-1, '0', '0');
        if (top >= 0) {
            temp = arr[top--];
        }
        return temp;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

void moveDisk(int disk, char source, char destination) {
    cout << "Move disk " << disk << " from " << source << " to " << destination << endl;
}

void moveDisksBetweenTwoPoles(Stack &src, Stack &dest, char s, char d) {
    Move pole1TopDisk = src.pop();
    Move pole2TopDisk = dest.pop();

    if (pole1TopDisk.disk == -1) {
        src.push(pole2TopDisk);
        moveDisk(pole2TopDisk.disk, d, s);
    } 
    else if (pole2TopDisk.disk == -1) {
        dest.push(pole1TopDisk);
        moveDisk(pole1TopDisk.disk, s, d);
    } 
    else if (pole1TopDisk.disk > pole2TopDisk.disk) {
        src.push(pole1TopDisk);
        dest.push(pole2TopDisk);
        moveDisk(pole2TopDisk.disk, d, s);
    } 
    else {
        dest.push(pole2TopDisk);
        src.push(pole1TopDisk);
        moveDisk(pole1TopDisk.disk, s, d);
    }
}

void towerOfHanoi(int num, Stack &src, Stack &aux, Stack &dest) {
    if (num <= 0 || num > 10) {
        cout << "Number of disks should be between 1 and 10" << endl;
        return;
    }

    int totalMoves = 0;
    for (int i = 1; i <= num; i++) {
        totalMoves = totalMoves * 2 + 1;
    }

    if (num % 2 == 0) {
        char temp = 'B';
        char destPole = 'C';
        for (int i = num; i >= 1; i--) {
            src.push(Move(i, 'A', '0'));
        }
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                moveDisksBetweenTwoPoles(src, dest, 'A', destPole);
            } 
            else if (i % 3 == 2) {
                moveDisksBetweenTwoPoles(src, aux, 'A', temp);
            }
             else {
                moveDisksBetweenTwoPoles(aux, dest, temp, destPole);
            }
        }
    }
     else {
        char temp = 'C';
        char destPole = 'B';
        for (int i = num; i >= 1; i--) {
            src.push(Move(i, 'A', '0'));
        }
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                moveDisksBetweenTwoPoles(src, aux, 'A', temp);
            } 
            else if (i % 3 == 2) {
                moveDisksBetweenTwoPoles(src, dest, 'A', destPole);
            } 
            else {
                moveDisksBetweenTwoPoles(aux, dest, temp, destPole);
            }
        }
    }

    cout << "Tower of Hanoi completed in " << totalMoves << " moves." << endl;
}

int main() {
    int disks;

    cout<<"Enter the number of disks: ";
    cin>>disks;

    Stack src, aux, dest;
    towerOfHanoi(disks, src, aux, dest);

}
