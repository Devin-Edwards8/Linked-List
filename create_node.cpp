#include "linked_list.h"

void create_node(Node **list_head_ptr, string student_name, int student_ID, float grades[12]) {
    Node *newNodePtr = (Node*) malloc(sizeof(Node));
    newNodePtr->student.name = student_name;
    newNodePtr->student.ID = student_ID;
    for(int i = 0; i < 12; i++)
        newNodePtr->student.grades[i] = grades[i];
    
    insert_node(list_head_ptr, newNodePtr);
}
