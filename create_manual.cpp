#include "linked_list.h"
#include <iostream>

using namespace std;

void create_manual(Node **list_head_ptr) {
    bool more_students = true;
    string choice, line;
    int count = 0;

    getline(cin, line); //consume line ?
    do {
        Node *newNodePtr = (Node *) malloc(sizeof(Node));
        cout << "Enter student name : ";
        getline(cin, newNodePtr->student.name);
        cout << "Enter student ID : ";
        getline(cin, line);
        newNodePtr->student.ID = stoi(line);
        for(int i = 0; i < 12; i++) {
            cout << "Enter student grade, or -1 if incomplete : ";
            getline(cin, line);
            newNodePtr->student.grades[i] = stof(line);
        }
        insert_node(list_head_ptr, newNodePtr);
        cout << "Would you like to enter another student? (yes or no) : ";
        getline(cin, choice);
        if(choice != "yes") {
            more_students = false;
        }
        count++;
    } while (more_students);

    cout << "A list of " << count << " students has been created. \n";

}
