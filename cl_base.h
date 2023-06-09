#ifndef CL_BASE_H
#define CL_BASE_H

#include "main.h"

class cl_base
{
public:
	cl_base(cl_base* = nullptr, std::string = "Base_object");
	
	cl_base* get_head_object();
	cl_base* get_object_by_name(std::string);
	cl_base* get_sub_object_by_name(std::string);
	cl_base* get_branch_object_by_name(std::string);

	std::string get_object_name();
	bool change_object_name(std::string);
	void change_object_state(int);
	
	void show_object_tree(int = 0);
	void show_traversal_tree(int = 0);
private:
	int i_object_state = 0;
	std::string s_object_name;
	cl_base* p_head_object = nullptr;
	std::vector<cl_base*> subordinate_objects;
};

#endif