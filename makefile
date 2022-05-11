all: list

list: main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp create_manual.cpp calculate_grade_by_ID.cpp quit.cpp calc_average.cpp calc_total.cpp delete_student.cpp update_grade.cpp add_student.cpp
	g++ -o out main.cpp insert_node.cpp create_node.cpp read_file.cpp print_list.cpp create_manual.cpp calculate_grade_by_ID.cpp quit.cpp calc_average.cpp calc_total.cpp delete_student.cpp update_grade.cpp add_student.cpp
