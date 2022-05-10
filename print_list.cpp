#include "linked_list.h"
#include <iostream>

void print_list(Node **list_head) {
    Node *traversePtr = *list_head;
    while(traversePtr != NULL) {
        cout << traversePtr->student.name << "\n";
        traversePtr = traversePtr->next;
    }
}
