#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    bool isThreadedLeft;
    bool isThreadedRight;

    TreeNode()
    {
        data = 0;
        left = right = nullptr;
        isThreadedLeft = isThreadedRight = true;
    }
};

class BinarySearchTree
{
public:
    TreeNode *dummy;
    TreeNode *root;

    BinarySearchTree()
    {
        dummy = new TreeNode();
        dummy->isThreadedLeft = true;
        dummy->isThreadedRight = false;
        root = nullptr;
    }

    TreeNode *findMax(TreeNode *node)
    {
        while (node->isThreadedRight == false)
        {
            node = node->right;
        }
        return node;
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->isThreadedLeft == false)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *search(int key)
    {
        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (key == temp->data)
            {
                return temp;
            }
            else if (key < temp->data && temp->isThreadedLeft == true)
            {
                return nullptr;
            }
            else if (key > temp->data && temp->isThreadedRight == true)
            {
                return nullptr;
            }
            else if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return nullptr;
    }

    void insert(int key)
    {
        TreeNode *newNode = new TreeNode();
        newNode->data = key;

        if (root == nullptr)
        {
            root = newNode;
            newNode->left = dummy;
            newNode->right = dummy;
            newNode->isThreadedLeft = true;
            newNode->isThreadedRight = true;
        }
        else
        {
            TreeNode *temp = root;
            while (true)
            {
                if (key < temp->data)
                {
                    if (temp->isThreadedLeft == false)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        newNode->left = temp->left;
                        newNode->right = temp;
                        temp->left = newNode;
                        temp->isThreadedLeft = false;
                        return;
                    }
                }
                else
                {
                    if (temp->isThreadedRight == false)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        newNode->right = temp->right;
                        newNode->left = temp;
                        temp->right = newNode;
                        temp->isThreadedRight = false;
                        return;
                    }
                }
            }
        }
    }

    TreeNode *Delete(int key)
    {
        TreeNode *current = root;
        TreeNode *parent = nullptr;

        if (root == nullptr)
        {
            cout << "Tree is Empty!" << endl;
            return root;
        }

        while (current != nullptr)
        {

            if (key == current->data)
            {
                if (current->isThreadedLeft && current->isThreadedRight)
                {
                    if (parent == nullptr)
                    {
                        delete current;
                        root = nullptr;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = nullptr;
                        parent->isThreadedLeft = true;
                        delete current;
                    }
                    else
                    {
                        parent->right = nullptr;
                        parent->isThreadedRight = true;
                        delete current;
                    }
                }
                else if (current->isThreadedLeft)
                {
                    if (parent == nullptr)
                    {

                        root = current->right;
                        delete current;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = current->right;
                        delete current;
                    }
                    else
                    {
                        parent->right = current->right;
                        delete current;
                    }
                }
                else if (current->isThreadedRight)
                {
                    if (parent == nullptr)
                    {
                        root = current->left;
                        delete current;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = current->left;
                        delete current;
                    }
                    else
                    {
                        parent->right = current->left;
                        delete current;
                    }
                }
                else
                {
                    TreeNode *successor = findMin(current->right);
                    current->data = successor->data;
                    current = successor;
                }
                return root;
            }
            else if (key < current->data)
            {
                if (current->isThreadedLeft)
                {
                    return root;
                }
                else
                {
                    parent = current;
                    current = current->left;
                }
            }
            else
            {
                if (current->isThreadedRight)
                {
                    return root;
                }
                else
                {
                    parent = current;
                    current = current->right;
                }
            }
        }

        cout << key << " not found in the tree." << endl;
        return root;
    }

    TreeNode *findNextInorderSuccessor(TreeNode *p)
    {
        if (p->isThreadedRight)
            return p->right;
        else
        {
            p = p->right;
            while (p->isThreadedLeft == false)
                p = p->left;
            return p;
        }
    }

    void update(int oldKey, int newKey)
    {
        TreeNode *nodeToUpdate = search(oldKey);
        if (nodeToUpdate != nullptr)
        {
            nodeToUpdate->data = newKey;
        }
        else
        {
            cout << "Node with key " << oldKey << " not found for update." << endl;
        }
    }

    void inorder(TreeNode *startNode)
    {
        TreeNode *temp = findMin(root);
        while (temp != dummy)
        {
            cout << temp->data << " ";
            temp = findNextInorderSuccessor(temp);
        }
    }

    void displayMenu()
    {
        int choice;
        int key, newKey;

        do
        {
            cout << "\nBinary Search Tree Menu:\ncout << 1. Insert\n2. Search\n3. Update\n4. Delete\n5. In-order Traversal\n6. Find Minimum\n7. Find Maximum\n8. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (search(key) != nullptr)
                    cout << key << " found in the tree." << endl;
                else
                    cout << key << " not found in the tree." << endl;
                break;

            case 3:
                cout << "Enter the key to update: ";
                cin >> key;
                cout << "Enter the new key: ";
                cin >> newKey;
                update(key, newKey);
                break;

            case 4:
                cout << "Enter key to delete: ";
                cin >> key;
                Delete(key);
                break;

            case 5:
                cout << "In-order traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Minimum value in the tree: " << findMin(root)->data << endl;
                break;

            case 7:
                cout << "Maximum value in the tree: " << findMax(root)->data << endl;
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 8);
    }
};

int main()
{
    BinarySearchTree tree;

    tree.displayMenu();

    return 0;
}
