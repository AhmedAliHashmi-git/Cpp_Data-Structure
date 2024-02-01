#include <iostream>

using namespace std;

class Node
{
public:
    string name;
    int power;
    Node *left;
    Node *right;

    Node(string name, int power)
    {
        this->name = name;
        this->power = power;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    ~Tree(){
        destroyTree(root);
    }

    void destroyTree(Node* root){

        if (root == NULL)
        {
            return;
        }
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        
    }


    Node *insert(Node *root, string name, int power)
    {
        if (root == NULL)
        {
            return new Node(name, power);
        }
        else if (power < root->power)
        {
            root->left = insert(root->left, name, power);
        }
        else if (power >= root->power)
        {
            root->right = insert(root->right, name, power);
        }
        return root;
    }

    void display(Node *root, int order)
    {
        if (root == NULL)
        {
            return;
        }

        if (order == 1)
            cout << root->name << " (" << root->power << ") "; // pre-order
        display(root->left, order);
        if (order == 2)
            cout << root->name << " (" << root->power << ") "; // In-order
        display(root->right, order);
        if (order == 3)
            cout << root->name << " (" << root->power << ") "; // post-order
    }

    Node *search(Node *root, int power)
    {
        if (root == NULL || root->power == power)
        {
            return root;
        }
        else if (power < root->power)
        {
            return search(root->left, power);
        }
        else if (power > root->power)
        {
            return search(root->right, power);
        }
    }

    Node *findMax(Node *root)
    {
        if (root == NULL || root->right == NULL)
        {
            return root;
        }
        return findMax(root->right);
    }

        Node *findMin(Node *root)
    {
        if (root == NULL || root->right == NULL)
        {
            return root;
        }
        return findMax(root->left);
    }
    


    Node *remove(Node *root, int power)
    {
        if (root == NULL)
        {
            return root;
        }
        if (power < root->power)
        {
            root->left = remove(root->left, power);
        }
        else if (power > root->power)
        {
            root->right = remove(root->right, power);
        }
        else
        {
            // one child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = findMin(root->left);

            root->name = temp->name;
            root->power = temp->power;

            root->left = remove(root->left, temp->power);
        }
        return root;
    }
};

int main()
{
    Tree Forest;
    Node *root = NULL;

    cout << "WELCOME TO THE MAGICAL FOREST";

    root = Forest.insert(root, "Diamond", 50);
    Forest.insert(root, "Ruby", 30);
    Forest.insert(root, "Sapphire", 70);
    Forest.insert(root, "Pearl", 40);
    Forest.insert(root, "Opal", 10);
    Forest.insert(root, "Garnet", 60);
    Forest.insert(root, "Zircon", 20);
    Forest.insert(root, "Jade", 5);

    int X;
    int currentPower = 0;
    cout << "\nHow much magical power can your bag hold?" << endl;
    cin >> X;

    while (currentPower < X)
    {

        cout << "\nEnchanted Forest Adventure Menu:" << endl;
        cout << "1. Display the magical tree (preorder, inorder, postorder)" << endl;
        cout << "2. Search for a gem by power" << endl;
        cout << "3. Find the gem with the highest magical power" << endl;
        cout << "4. Pluck (remove) a gem and put it in your bag" << endl;
        cout << "5. Exit the forest" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int order;
            cout << "Enter the traversal order \n1.preorder\n2.inorder\n3.postorder ";
            cin >> order;
            Forest.display(root, order);
            cout << endl;
        }
        else if (choice == 2)
        {
            int searchPower;
            cout << "Enter the power to search for: ";
            cin >> searchPower;
            Node *gem = Forest.search(root, searchPower);
            if (gem != NULL)
            {
                cout << "Gem found: " << gem->name << " [" << gem->power << "]" << endl;
            }
            else
            {
                cout << "Gem not found." << endl;
            }
        }
        else if (choice == 3)
        {
            Node *highestPowerGem = Forest.findMax(root);
            cout << "Gem with the highest magical power: " << highestPowerGem->name << " (" << highestPowerGem->power << ")" << endl;
        }
        else if (choice == 4)
        {
            if (currentPower >= X)
            {
                cout << "Your bag is already filled. You won! Now take your bag and run from the forest." << endl;
            }

            else if (currentPower < X)
            {
                int gempower;
                Forest.display(root, 1);
                cout << "Which gem to pluck?" << endl;
                cout << "Enter the power : ";
                cin >> gempower;
                Node *gem = Forest.search(root, gempower);
                if (gem != NULL)
                {
                    cout << "You Plucked: " << gem->name << " [" << gem->power << "]" << endl;
                    Forest.remove(root, gempower);
                    currentPower = currentPower + gempower;
                }
                else
                {
                    cout << "Gem not found." << endl;
                }
                cout << "Power in bag : " << currentPower << endl;
            }

            if (currentPower == X)
            {
                cout << "\nRUNNNNN...";
            }
        }
        else if (choice == 5)
        {
            cout << "You decided to exit the forest." << endl;
            return 0;
        }
        else
        {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
