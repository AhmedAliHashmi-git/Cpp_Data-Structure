#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    int employeeID;
    string name;
    float sales;
    float customerSatisfaction;
    float projectCompletion;
    float performanceScore;

    Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion, float sales) {
        this->employeeID = employeeID;
        this->name = name;
        this->customerSatisfaction = customerSatisfaction;
        this->projectCompletion = projectCompletion;
        this->sales = sales;
        calculatePerformanceScore();
    }

    void calculatePerformanceScore() {
        performanceScore = sales + customerSatisfaction + projectCompletion;
    }
};

class MaxHeap {
public:
    vector<Employee> employeeHeap;

    int getParent(int child) {
        int p=(child-1)/2;

        if(child==0)
        {
        return -1;
        }
        else
        {
        return p;
        }
    }

    int getLeft(int parent) {
        int child= 2*parent+1;
        if(child<employeeHeap.size())
        {
        return child;
        }
        else    
        {
        return -1;
}
    }

    int getRight(int parent) {
        int child= 2*parent+2;
        if(child<employeeHeap.size())
        {
        return child;
        }
        else
        {
        return -1;
    }
    }

    void swap(Employee &a, Employee &b) {
        Employee temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int node) {
        int parent = getParent(node);
        if (node > 0 && parent >= 0 && employeeHeap[parent].performanceScore < employeeHeap[node].performanceScore) {
            swap(employeeHeap[node], employeeHeap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node) {
        int leftChild = getLeft(node);
        int rightChild = getRight(node);
        int largest = node;

        if (leftChild < employeeHeap.size() && employeeHeap[leftChild].performanceScore > employeeHeap[largest].performanceScore) {
            largest = leftChild;
        }

        if (rightChild < employeeHeap.size() && employeeHeap[rightChild].performanceScore > employeeHeap[largest].performanceScore) {
            largest = rightChild;
        }

        if (largest != node) {
            swap(employeeHeap[node], employeeHeap[largest]);
            heapifyDown(largest);
        }
    }

    void insertEmployee( Employee employee) {
        employeeHeap.push_back(employee);
        heapifyUp(employeeHeap.size() - 1);
    }

    void getTopRankingEmployee() {
        if (employeeHeap.empty()) {
            cout << "No Employees." << endl;
            return;
        }

        Employee topEmployee = employeeHeap[0];
        cout<<"Top-Ranking Employee: ";
        cout<<"Employee ID: " << topEmployee.employeeID << ", Name: " << topEmployee.name << ", Performance Score: " << topEmployee.performanceScore << endl;

        swap(employeeHeap[0], employeeHeap[employeeHeap.size() - 1]);
        employeeHeap.pop_back();
        heapifyDown(0);
    }

    void updatePerformance(int employeeID, float newSales, float newCS, float newPCE) {
        for (Employee emp : employeeHeap) {
            if (emp.employeeID == employeeID) {
                emp.sales = newSales;
                emp.customerSatisfaction = newCS;
                emp.projectCompletion = newPCE;
                emp.calculatePerformanceScore();
                int index = &emp - &employeeHeap[0];
                heapifyUp(index);
                heapifyDown(index);
                cout << "Employee performance updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found with ID: " << employeeID << endl;
    }

    void displayEmployees() {
        if (employeeHeap.empty()) {
            cout << "No Employees." << endl;
            return;
        }
        cout << "Employee Rankings:" << endl;
        for (const Employee &emp : employeeHeap) {
            cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
        }
    }
};

int main() {
    MaxHeap employeeMaxHeap;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter a new employee details\n";
        cout << "2. Get the top-ranking employee\n";
        cout << "3. Update an employee's scores\n";
        cout << "4. Display employee rankings\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name;
                float sales, cs, pce;
                cout << "Enter Employee ID: ";
                cin >> id;
                cin.ignore(); // Clear newline character from the buffer
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Sales (in percentage): ";
                cin >> sales;
                cout << "Enter Customer Satisfaction (in percentage): ";
                cin >> cs;
                cout << "Enter Project Completion Efficiency (in percentage): ";
                cin >> pce;

                Employee newEmployee(id, name, cs, pce, sales);
                employeeMaxHeap.insertEmployee(newEmployee);
                cout << "Employee added successfully!" << endl;
                break;
            }
            case 2: {
                employeeMaxHeap.getTopRankingEmployee();
                break;
            }
            case 3: {
                int empID;
                float newSales, newCS, newPCE;
                cout << "Enter Employee ID to update scores: ";
                cin >> empID;
                cout << "Enter new Sales (in percentage): ";
                cin >> newSales;
                cout << "Enter new Customer Satisfaction (in percentage): ";
                cin >> newCS;
                cout << "Enter new Project Completion Efficiency (in percentage): ";
                cin >> newPCE;
                employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
                break;
            }
            case 4: {
                employeeMaxHeap.displayEmployees();
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
