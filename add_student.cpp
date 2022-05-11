#include "linked_list.h"
#include <iostream>\

void add_student(Node **list_head_ptr) {
    string name, line;
    getline(cin, line); //consume line ?
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
}
