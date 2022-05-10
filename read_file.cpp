#include "linked_list.h"
#include <fstream>

void read_file(Node **list_head_ptr, string filename) {
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
