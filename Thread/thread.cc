#include <iostream>
using namespace std;
#define SPACE 10

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool LTH, RTH;
    // initialize in constructor initially and then change in insert method accordingly

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        LTH = true;
        RTH = true;
    }
    
};

class Tree
{
public:
    Node *root;
    Node *Dummy = new Node(-1);

    Tree()
    {
        root = NULL;
        Dummy->left = Dummy;
        Dummy->right = Dummy;
    }

    Node *findMax()
    {
        while (root->RTH != true)
        {
            root = root->right;
        }
        return root;
    }

    Node *findMin()
    {
        while (root->LTH != true)
        {
            root = root->left;
        }
        return root;
    }

    Node *search(int key)
    {
        // iteratively find the node if it exists
    }

    Node *insert(Node *root, int key)
    {
        if (root == NULL)
        {
            // Dummy->left = new Node(key);
            root = new Node(key);
            Dummy->left = root;
            Dummy->LTH = false;
            root->left = Dummy;
            root->right = Dummy;
            return root;
        }

        if (key > root->data)
        {
            if (root->RTH == true)
            {
                Node *temp = new Node(key);
                temp->right = root->right;
                temp->left = root;
                root->RTH = false;
                root->right = temp;
                return temp;
            }

            else
            {
                root->right = insert(root->right, key);
            }
        }

        if (key < root->data)
        {
            if (root->LTH == true)
            {
                Node *temp = new Node(key);
                temp->left = root->left;
                root->LTH = false;
                temp->right = root;
                root->left = temp;
                return temp;
            }
            root->left = insert(root->left, key);
        }

        return root;
    }

    Node *findNextInorderSuccessor(Node *node)
    {
        if (node->LTH == node->RTH == true)
        {
            if (node->right == Dummy)
            {
                cout << "In order successor not found " << endl;
                return NULL;
            }
            return node->right;
        }
        else
        {

            node = node->right;
            while (node->LTH != true)
            {
                node = node->left;
            }
            return node;
        }
    }

    void inorder(Node *root)
    {
        Node *temp;
        temp = findNextInorderSuccessor(root);
        cout << temp->data;
        //     if (root == NULL)
        //         return;

        //     Node *current = findMin(); // Start from the leftmost node

        //    while(current->right != Dummy){
        //     cout<<current->data<<" ";
        //     current = current->right;
        //    }
    }

    void print2D(Node *root, int space)
    {
        if (root == NULL) // Base case  1
            return;
        space += SPACE;              // Increase distance between levels   2
        print2D(root->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
        cout << " ";                    // 5.1
        cout << root->data << "\n";         // 6
        print2D(root->left, space);         // Process left child  7
    }
};

void displayMenu()
{
    cout << "Binary Search Tree Menu:" << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Inorder traversal" << endl;
    cout << "3. print 2D" << endl;
    cout << "4. Exit" << endl;
}

int main()
{
    Tree t;
    Node *root = NULL;

    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            root = t.insert(root, value);
            break;
        }
        case 2:
            cout << "Inorder traversal: ";
            t.inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "2D Printing: ";
            t.print2D(root, 5);
            cout << endl;
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}