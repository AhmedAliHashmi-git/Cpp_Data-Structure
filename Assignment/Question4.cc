#include <iostream>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;

    Employee(int id, string name, string designation)
        : id(id), name(name), designation(designation) {}
};

struct Node {
    Employee data;
    Node* left;
    Node* right;
    int height;

    Node(Employee data) : data(data), left(nullptr), right(nullptr), height(1) {}
};

// AVLTree class
class AVLTree {
private:
    Node* root;

    int height(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }

        return temp->height;
    }

    int balanceFactor(Node* temp) {
        if (temp == nullptr) {
            return 0;
        }

        return height(temp->left) - height(temp->right);
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = getMax(height(y->left), height(y->right)) + 1;
        x->height = getMax(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = getMax(height(x->left), height(x->right)) + 1;
        y->height = getMax(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getMax(int a, int b) {
        return (a > b) ? a : b;
    }

    Node* insert(Node* temp, Employee emp) {
        if (temp == nullptr) {
            return new Node(emp);
        }

        if (emp.id < temp->data.id) {
            temp->left = insert(temp->left, emp);
        } else if (emp.id > temp->data.id) {
            temp->right = insert(temp->right, emp);
        } else {
            return temp;
        }

        temp->height = 1 + getMax(height(temp->left), height(temp->right));

        int balance = balanceFactor(temp);

        // Left-Left Case
        if (balance > 1 && emp.id < temp->left->data.id)
            return rotateRight(temp);

        // Right-Right Case
        if (balance < -1 && emp.id > temp->right->data.id)
            return rotateLeft(temp);

        // Left-Right Case
        if (balance > 1 && emp.id > temp->left->data.id) {
            temp->left = rotateLeft(temp->left);
            return rotateRight(temp);
        }

        // Right-Left Case
        if (balance < -1 && emp.id < temp->right->data.id) {
            temp->right = rotateRight(temp->right);
            return rotateLeft(temp);
        }

        return temp;
    }

    Node* minValueNode(Node* temp) {
        Node* current = temp;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int id) {
        if (root == nullptr)
            return root;

        if (id < root->data.id)
            root->left = deleteNode(root->left, id);
        else if (id > root->data.id)
            root->right = deleteNode(root->right, id);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data.id);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + getMax(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        // Left-Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rotateRight(root);

        // Left-Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right-Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return rotateLeft(root);

        // Right-Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    Node* search(Node* temp, int id) {
        if (temp == nullptr || temp->data.id == id)
            return temp;

        if (id < temp->data.id)
            return search(temp->left, id);

        return search(temp->right, id);
    }

    void printOrganizationalChart(Node* temp, int space) {
        const int COUNT = 5;

        if (temp == nullptr)
            return;

        space += COUNT;

        printOrganizationalChart(temp->right, space);

        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";

        cout << temp->data.name << " (" << temp->data.designation << ")" << endl;

        printOrganizationalChart(temp->left, space);
    }

public:
    AVLTree() : root(nullptr) {}

    void addEmployee(int id, string name, string designation) {
        Employee newEmployee(id, name, designation);
        root = insert(root, newEmployee);
        cout << "Employee added successfully." << endl;
        balanceAndDisplay();
    }

    void searchEmployee(int id) {
        Node* result = search(root, id);

        if (result != nullptr) {
            cout << "Employee Found:" << endl;
            cout << "ID: " << result->data.id << endl;
                        cout << "Name: " << result->data.name << endl;
            cout << "Designation: " << result->data.designation << endl;
        } else {
            cout << "Employee not found with ID: " << id << endl;
        }
    }

    void generateOrganizationalChart() {
        cout << "Organizational Chart:" << endl;
        printOrganizationalChart(root, 0);
    }

    void updateEmployee(int id, string newName, string newDesignation) {
        Node* result = search(root, id);

        if (result != nullptr) {
            result->data.name = newName;
            result->data.designation = newDesignation;
                        cout << "Employee information updated successfully." << endl;
            balanceAndDisplay();
        } else {
            cout << "Employee not found with ID: " << id << endl;
        }
    }

    void removeEmployee(int id) {
        Node* result = search(root, id);

        if (result != nullptr) {
            root = deleteNode(root, id);
            cout << "Employee removed successfully." << endl;
            balanceAndDisplay();
        } else {
            cout << "Employee not found with ID: " << id << endl;
        }
    }

    void balanceAndDisplay() {
        cout << "Tree after balancing:" << endl;
        printOrganizationalChart(root, 0);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    while (true) {
        cout << "\nMenu:\n1. Add Employee\n2. Search for Employee\n3. Generate Organizational Chart\n4. Modify Employee Information\n5. Remove Employee\n6. Exit\n";

        int choice, id;
        string name, designation;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Employee Designation: ";
                getline(cin, designation);
                avl.addEmployee(id, name, designation);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                avl.searchEmployee(id);
                break;

            case 3:
                avl.generateOrganizationalChart();
                break;

            case 4:
                cout << "Enter Employee ID to update: ";
                cin >> id;
                cout << "Enter New Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter New Employee Designation: ";
                getline(cin, designation);
                avl.updateEmployee(id, name, designation);
                break;

            case 5:
                cout << "Enter Employee ID to remove: ";
                cin >> id;
                avl.removeEmployee(id);
                break;

            case 6:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

