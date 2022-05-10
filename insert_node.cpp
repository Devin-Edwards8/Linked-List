#include "linked_list.h"

void insert_node(Node **list_head_ptr, Node *newNodePtr) {
    newNodePtr->next = *list_head_ptr;
    *list_head_ptr = newNodePtr;
}
