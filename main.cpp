#include <fstream>
#include "linked_list.h"

using namespace std;

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
