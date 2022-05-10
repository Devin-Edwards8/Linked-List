all: list

list: main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp
	g++ -o out main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp
