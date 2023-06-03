#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Record {
    int id;
    char name[20];
    float salary;
};
const int MAX_RECORDS = 100;
const int RECORD_SIZE = sizeof(Record);
void insertRecord(fstream& file, Record& record) {
    file.seekp((record.id - 1) * RECORD_SIZE);
    file.write(reinterpret_cast<char*>(&record), RECORD_SIZE);
    cout << "Record inserted successfully." << endl;
}
void deleteRecord(fstream& file, int id) {
    Record blankRecord = {0, "", 0.0};
    file.seekp((id - 1) * RECORD_SIZE);
    file.write(reinterpret_cast<char*>(&blankRecord), RECORD_SIZE);
    cout << "Record deleted successfully." << endl;
}
void displayRecords(fstream& file) {
    Record record;
    cout << "ID\tName\t\tSalary" << endl;
    for (int i = 1; i <= MAX_RECORDS; i++) {
        file.seekg((i - 1) * RECORD_SIZE);
        file.read(reinterpret_cast<char*>(&record), RECORD_SIZE);
        if (record.id != 0) {
            cout << record.id << "\t" << setw(20) << left << record.name << "\t" << record.salary << endl;
        }
    }
}
int main() {
    fstream file("data.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int choice;
    do {
        cout << endl << "1. Insert Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Display Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Record record;
                cout << "Enter ID: ";
                cin >> record.id;
                cout << "Enter Name: ";
                cin.ignore();
                cin.getline(record.name, 20);
                cout << "Enter Salary: ";
                cin >> record.salary;
                insertRecord(file, record);
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of the record to delete: ";
                cin >> id;
                deleteRecord(file, id);
                break;
            }
            case 3:
                displayRecords(file);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
    file.close();
    return 0;
}
