#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Data {
    string name;
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

void create_node(Node **list_head_ptr, string student_name, int student_ID, float grades[12]) {
    Node *newNodePtr = (Node*) malloc(sizeof(Node));
    newNodePtr->student.name = student_name;
    newNodePtr->student.ID = student_ID;
    for(int i = 0; i < 12; i++)
        newNodePtr->student.grades[i] = grades[i];
    
    insert_node(list_head_ptr, newNodePtr);
}

void read_file(Node **list_head_ptr, string filename){
    string line, student_name;
    int student_ID = 0;
    float grades[12];
    for(int i = 0; i < 12; i++)
        grades[i] = 0;
    ifstream records;
    records.open(filename, ios::in);
    getline(records, line); // consume header
    
    while(!records.eof()) {
        
        getline(records, student_name);
        getline(records, line);
        student_ID = stoi(line);
        
        for(int i = 0; i < 12; i++) {
            records >> line;
            grades[i] = stof(line);
        }
        getline(records, line); //consume whitespace ?
        
        create_node(list_head_ptr, student_name, student_ID, grades);
    }
    records.close();
}

void print_list(Node **list_head) {
    Node *traversePtr = *list_head;
    while(traversePtr != NULL) {
        cout << traversePtr->student.name << "\n";
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
