#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};
void addEmployee(fstream& file) {
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cout << "Enter employee name: ";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter employee designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter employee salary: ";
    cin >> emp.salary;
    file.write((char*)&emp, sizeof(Employee));
}
void deleteEmployee(fstream& file) {
    int id;
    cout << "Enter the ID of the employee to be deleted: ";
    cin >> id;
    Employee emp;
    bool found = false;
    file.seekg(0, ios::beg);
    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.id == id) {
            found = true;
            break;
        }
    }
    if (found) {
        file.seekg(-sizeof(Employee), ios::cur);
        emp.id = -1; // Set the ID to -1 to indicate deletion
        file.write((char*)&emp, sizeof(Employee));
        cout << "Employee with ID " << id << " has been deleted." << endl;
    } else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}
void displayEmployee(fstream& file) {
    int id;
    cout << "Enter the ID of the employee to be displayed: ";
    cin >> id;
    // Search for the employee by ID
    Employee emp;
    bool found = false;
    file.seekg(0, ios::beg);
    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.id == id) {
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Employee ID: " << emp.id << endl;
        cout << "Employee name: " << emp.name << endl;
        cout << "Employee designation: " << emp.designation << endl;
        cout << "Employee salary: " << emp.salary << endl;
    } else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

int main() {
    fstream file("employee.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }
    int choice;
    do {
        cout << "1. Add employee information" << endl;
        cout << "2. Delete employee information" << endl;
        cout << "3. Display employee information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                deleteEmployee(file);
                break;
            case 3:
                displayEmployee(file);
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    file.close();
    return 0;
}
