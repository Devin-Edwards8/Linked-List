#include "linked_list.h"
#include <fstream>


void quit(Node **list_head_ptr, string cats[4]) {
    ofstream records;
    records.open("updated_records.txt", ios::out);

    for(int i = 0; i < 4; i++)
        records << cats[i] << " ";
    Node *prevPtr = *list_head_ptr;
    Node *traversePtr = prevPtr->next;
    while(prevPtr != NULL) {
        records << "\n" << prevPtr->student.name;
        records << "\n" << prevPtr->student.ID;
        for(int i = 0; i < 4; i++){
            records << "\n";
            for(int j = 3*i; j < 3*i + 3; j++) {
                records << prevPtr->student.grades[j] << " ";
            }
        }
        free(prevPtr);
        prevPtr = traversePtr;
        if(traversePtr != NULL) {
            traversePtr = traversePtr->next;
        }
    }
    records.close();
}
