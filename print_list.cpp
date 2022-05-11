#include "linked_list.h"
#include <iostream>

/*This is a test function, to see if the list is created properly*/
void print_list(Node **list_head) {
    Node *traversePtr = *list_head;
    while(traversePtr != NULL) {
        cout << traversePtr->student.name << "\n";
        cout << traversePtr->student.ID << "\n";
        for(int i = 0; i < 12; i++) {
            cout << traversePtr->student.grades[i] << " ";
        }
        traversePtr = traversePtr->next;
    }
}
