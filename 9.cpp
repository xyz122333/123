#include <iostream>
#include <string>
#include <map>
using namespace std;

class Dictionary {
public:
    map<string, string> data;
    void addKeyword(string keyword, string meaning) { data[keyword] = meaning; } 
    void deleteKeyword(string keyword) { data.erase(keyword); } 
    void updateKeyword(string keyword, string newMeaning) { data[keyword] = newMeaning; } 
    void displayAscending() {
        for (auto it = data.begin(); it != data.end(); ++it) { cout << it->first << ": " << it->second << endl; }
    }
    void displayDescending() {
        for (auto it = data.rbegin(); it != data.rend(); ++it) { cout << it->first << ": " << it->second << endl; }
    }
    int getMaxComparisons(string keyword) {
        int count = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            ++count;
            if (it->first == keyword) return count;
        }
        return count;
    }
};
void printMenu() {
    cout << "1. Add keyword" << endl;
    cout << "2. Delete keyword" << endl;
    cout << "3. Update keyword" << endl;
    cout << "4. Display ascending" << endl;
    cout << "5. Display descending" << endl;
    cout << "6. Find max comparisons" << endl;
    cout << "7. Quit" << endl;
    cout << "Enter your choice: ";
}
int main() {
    Dictionary dict;
    int choice;
    string keyword, meaning;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin >> meaning;
                dict.addKeyword(keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword: ";
                cin >> keyword;
                dict.deleteKeyword(keyword);
                break;
            case 3:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter new meaning: ";
                cin >> meaning;
                dict.updateKeyword(keyword, meaning);
                break;
            case 4:
                cout << "Ascending order:" << endl;
                dict.displayAscending();
                break;
            case 5:
                cout << "Descending order:" << endl;
                dict.displayDescending();
                break;
            case 6:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Max comparisons for '" << keyword << "': " << dict.getMaxComparisons(keyword) << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 7);
    return 0;
}
