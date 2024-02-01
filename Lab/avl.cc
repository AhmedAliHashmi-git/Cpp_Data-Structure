#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
    Node() {
        left = right = nullptr;
    }
};

class AVLTree {
public:
    int key;
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    int height(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }

        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int balanceFactor(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }
        return height(temp->left) - height(temp->right);
    }

    Node* rotateLeft(Node* root) {
        Node* temp1 = root->right;
        root->right = temp1->left;
        temp1->left = root;
        return temp1;
    }

    Node* rotateRight(Node* root) {
        Node* temp1 = root->left;
        root->left = temp1->right;
        temp1->right = root;
        return temp1;
    }

    Node* insert(Node* temp, int num) {
        if (temp == nullptr) {
            temp = new Node;
            temp->info = num;
            return temp;
        }

        if (num < temp->info) {
            temp->left = insert(temp->left, num);
        } else if (num > temp->info) {
            temp->right = insert(temp->right, num);
        }

        int bf = balanceFactor(temp);

        if (bf >= 2) {
            if (num < temp->left->info) {
                temp = rotateRight(temp);
            } else if (num > temp->left->info) {
                temp->left = rotateLeft(temp->left);
                temp = rotateRight(temp);
            }
        } else if (bf <= -2) {
            if (num > temp->right->info) {
                temp = rotateLeft(temp);
            } else if (num < temp->right->info) {
                temp->right = rotateRight(temp->right);
                temp = rotateLeft(temp);
            }
        }

        return temp;
    }

    void insert(int num) {
        root = insert(root, num);
        cout << "Value " << num << " inserted successfully." << endl;
        balanceAndDisplay();
    }

    void balanceAndDisplay() {
        cout << "Tree after balancing:" << endl;
        preOrder(root);
        cout << endl;
    }

    void preOrder(Node* temp) {
        if (temp == nullptr) {
            return;
        }
        cout << temp->info << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }

    bool search(int num, Node* temp) {
        if (temp == nullptr) {
            return false;
        }
        if (num == temp->info) {
            return true;
        } else if (num < temp->info) {
            return search(num, temp->left);
        } else {
            return search(num, temp->right);
        }
    }

    bool search(int num) {
        return search(num, root);
    }

   int findMax(Node* temp) {
    if (temp == nullptr) {
        cout << "Tree is empty." << endl;
        return 0;
    }

    while (temp->right != nullptr) {
        temp = temp->right;
    }

    return temp->info;
}


    int findMin(Node* temp) {
        if (temp == nullptr) {
            cout << "Tree is empty" << endl;
            return 0;
        }

        while (temp->left != nullptr) {
            temp = temp->left;
        }

        return temp->info;
    }

    void update(Node* temp, int num) {
        if (temp == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        if (num < temp->info) {
            update(temp->left, num);
        } else if (num > temp->info) {
            update(temp->right, num);
        } else {
            temp->info = key;
        }
    }

    Node* findAndDeleteMin(Node* temp) {
        if (temp == nullptr) {
            return temp;
        }

        if (temp->left != nullptr) {
            temp->left = findAndDeleteMin(temp->left);
        } else {
            Node* temp2 = temp->right;
            delete temp;
            return temp2;
        }

        return temp;
    }

    Node* deleteNode(Node* temp, int num) {
        if (temp == nullptr) {
            return temp;
        }

        if (num < temp->info) {
            temp->left = deleteNode(temp->left, num);
        } else if (num > temp->info) {
            temp->right = deleteNode(temp->right, num);
        } else {
            if (temp->left == nullptr || temp->right == nullptr) {
                Node* temp2 = (temp->left) ? temp->left : temp->right;
                if (temp2 == nullptr) {
                    temp2 = temp;
                    temp = nullptr;
                } else {
                    *temp = *temp2;
                }
                delete temp2;
            } else {
                int minValue = findMin(temp->right);
                temp->info = minValue;
                temp->right = findAndDeleteMin(temp->right);
            }
        }

        if (temp == nullptr) {
            return temp;
        }

        int bf = balanceFactor(temp);

        if (bf >= 2) {
            if (balanceFactor(temp->left) <= -1) {
                temp->left = rotateLeft(temp->left);
            }
            temp = rotateRight(temp);
        } else if (bf <= -2) {
            if (balanceFactor(temp->right) >= 1) {
                temp->right = rotateRight(temp->right);
            }
            temp = rotateLeft(temp);
        }

        return temp;
    }

    void deleteValue(int num) {
        root = deleteNode(root, num);
        cout << "Value " << num << " deleted successfully." << endl;
        balanceAndDisplay();
    }
};


int main() {
    AVLTree avl;

    while (true) {
        cout << "\nMenu:\n1. Insert a value\n2. Delete a value\n3. Display tree (In order traversal)\n4. Update a value (Not implemented)\n5. Search a value\n6. Find max\n7. Find min\n8. Exit\n";

        int choice, num;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter a value to insert: ";
            cin >> num;
            avl.insert(num);
        } 
        else if (choice == 2) {
             cout << "Enter a value to delete: ";
            cin >> num;
            avl.deleteValue(num);
        } 
        else if (choice == 3) {
            cout << "Tree (In order traversal): ";
            avl.preOrder(avl.root);
            cout << endl;
        } 
        else if (choice == 4) {
            int key2;
            cout<<"Enter the key you weant to update: ";
            cin>>key2;
            cout<<"Enter the updated value:  ";
            cin>>avl.key;
            avl.update(avl.root ,key2);
            avl.preOrder(avl.root);

        } 
        else if (choice == 5) {
            cout << "Enter a value to search: ";
            cin >> num;
           
            if (avl.search(num)) {
                cout << num << " found in the tree." << endl;
            } 
            else {
                cout << num << " not found in the tree." << endl;
            }
        } 
        else if (choice == 6) {
           int maxVal = avl.findMax(avl.root);
       
        if (maxVal != 0) {
        cout << "Max value in the tree: " << maxVal << endl;
        }
        } 
        else if (choice == 7) {
            int minVal = avl.findMin(avl.root);
         if (minVal != 0) {
        cout << "Min value in the tree: " << minVal << endl;
        }
        } 
        
        else if (choice == 8) {
            cout << "Exiting program." << endl;
            return 0;
        }
    }
}

