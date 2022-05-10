all: list

list: main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp create_manual.cpp
	g++ -o out main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp create_manual.cpp
