#include <string>

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

void insert_node(Node **list_head_ptr, Node *newNodePtr);

void create_node(Node **list_head_ptr, string student_name, int student_ID, float grades[12]);

int read_file(Node **list_head_ptr, string filename);

void print_list(Node **list_head);

void create_manual(Node **list_head_ptr);
