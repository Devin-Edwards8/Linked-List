#include <fstream>
#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    Node *list_head = NULL;
    string choice, cats[4];

    cout << "Would you like to enter a file with student info? (yes or no) : ";
    cin >> choice;
    if(choice == "yes") {
        string line, filename;
        cout << "Enter filename : ";
        cin >> filename;
        ifstream records;
        records.open(filename, ios::in);
        for(int i = 0; i < 4; i++) {
            records >> cats[i];
        }
        records.close();
        int count = read_file(&list_head, filename);
        cout << "\nA list of " << count << " students has been created. \n";
    } else {
        cout << "Enter Student Info Manually. \n";
        create_manual(&list_head);
    }

    bool done = false;
    while(!done) {
        cout << " --------------------------------------------------------------------\n";
        cout << "|                   What would you like to do?                       | \n";
        cout << "|      Enter 1 to caluclate a student's grade                        |\n";
        cout << "|      Enter 2 to delete a student's records                         |\n";
        cout << "|      Enter 3 to update a student's grade                           |\n";
        cout << "|      Enter 4 to add a student's records                            |\n";
        cout << "|      Enter 5 to quit and store records in a file                   |\n";
        cout << " --------------------------------------------------------------------\n";
        cin >> choice;
        bool is_int = true;
        for(int i = 0; i < choice.length(); i++) {
            if(isdigit(choice[i]) == 0) {
                is_int = false;
            }
        }
        int action;
        if(is_int) {
            action = stoi(choice);
        } else {
            action = 0;
        }

        switch(action) {
            case 1:
                calculate_grade_by_ID(list_head);
                break;
            case 2:
                delete_student(list_head);
                break;
            case 3:
                update_grade(list_head);
                break;
            case 4:
                add_student(&list_head);
                break;
            case 5:
                quit(&list_head, cats);
                cout << "\nStudent records have been stored in updated_records.txt\n";
                done = true;
                break;
            default:
                cout << "invalid input\n";
                break;
        }
    }
    
    return 0;
}
