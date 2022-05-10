#include <fstream>
#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    Node *list_head = NULL;
    string choice;

    cout << "Would you like to enter a file with student info? (yes or no) : ";
    cin >> choice;
    if(choice == "yes") {
        string line, cats[4], filename;
        cout << "Enter filename : ";
        cin >> filename;
        ifstream records;
        records.open(filename, ios::in);
        records.close();
        int count = read_file(&list_head, filename);
        cout << "A list of " << count << " students has been created. \n";
    } else {
        cout << "Enter Student Info Manually. \n";
        create_manual(&list_head);
    }
    
    return 0;
}
