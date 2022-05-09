#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Data {
    string first_name;
    string last_name;
    float grades[12];
    int ID;
};

typedef struct Node{
    Data student;
    Node *next;
} Node;

void insert_node(Node **list_head_ptr, Node *newNodePtr) {
    newNodePtr->next = *list_head_ptr;
    *list_head_ptr = newNodePtr;
}

void createNode(Node **list_head_ptr, string first_name, string last_name, int student_ID, float grades[12]) {
    Node *newNodePtr = (Node*) malloc(sizeof(Node));
    newNodePtr->student.first_name = first_name;
    newNodePtr->student.last_name = last_name;
    newNodePtr->student.ID = student_ID;
    for(int i = 0; i < 12; i++)
        newNodePtr->student.grades[i] = grades[i];
    
    insert_node(list_head_ptr, newNodePtr);
}

void read_file(Node **list_head_ptr, string filename){
    string line, first_name, last_name;
    int student_ID;
    float grades[12];
    ifstream records;
    records.open(filename, ios::in);
    for(int i = 0; i < 4; i++) {
        records >> line; //eat categories
    }
    //while(!records.eof()) {
        records >> first_name;
        records >> last_name;
        records >> student_ID;
        for(int i = 0; i < 12; i++)
            records >> grades[i];
        createNode(list_head_ptr, first_name, last_name, student_ID, grades[12]);
    //}
    records.close();
}

void print_list(Node **list_head) {
    Node *traversePtr = *list_head;
    while(traversePtr != NULL) {
        cout << traversePtr->student.first_name;
        traversePtr = traversePtr->next;
    }
}

int main() {
    Node *list_head = NULL;
    string line, cats[4];
    ifstream records;
    records.open("class_records", ios::in);
    for(int i = 0; i < 4; i++) {
        records >> line;
        cats[i] = line;
    }
    records.close();
    read_file(&list_head, "class_records");
    
    print_list(&list_head);
    
    return 0;
}
