#include "cl_base.h"

cl_base::cl_base(cl_base* p_head_object, std::string s_object_name)
{
	this->p_head_object = p_head_object;
	this->s_object_name = s_object_name;
	if (p_head_object) p_head_object->subordinate_objects.push_back(this);
}

cl_base* cl_base::get_head_object()
{
	return p_head_object;
}

cl_base* cl_base::get_object_by_name(std::string s_object_name)
{
	cl_base* base = this;
	while (true) if (base->get_head_object()) base = base->get_head_object();
	else break;

	if (base->get_branch_object_by_name(s_object_name)) return base->get_branch_object_by_name(s_object_name);
	return nullptr;
}

cl_base* cl_base::get_sub_object_by_name(std::string s_object_name)
{
	if (!s_object_name.empty()) for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_object_name() == s_object_name) return subordinate_object;
	return nullptr;
}

cl_base* cl_base::get_branch_object_by_name(std::string s_object_name)
{
	if (this->s_object_name == s_object_name) return this;

	for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_object_name() == s_object_name) return subordinate_object;
	for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_branch_object_by_name(s_object_name)) return subordinate_object->get_branch_object_by_name(s_object_name);

	return nullptr;
}

std::string cl_base::get_object_name()
{
	return s_object_name;
}

bool cl_base::change_object_name(std::string s_object_name)
{
	if (s_object_name.empty()) return false;
	for (cl_base* subordinate_object : subordinate_objects) if (subordinate_object->get_object_name() == s_object_name) return false;
	
	this->s_object_name = s_object_name;
	return true;
}

void cl_base::change_object_state(int i_object_state)
{
	this->i_object_state = i_object_state;
	if (this->i_object_state == 0) for (cl_base* subordinate_object : subordinate_objects) subordinate_object->change_object_state(i_object_state);

	cl_base* base = this;
	while (true)
	{
		if (base->get_head_object())
		{
			base = base->get_head_object();
			if (i_object_state == 0) base->change_object_state(0);
		}
		else break;
	}
}

void cl_base::show_object_tree(int depth)
{
	std::cout << std::endl << std::string(depth * 4, ' ') << s_object_name;
	for (cl_base* subordinate_object : subordinate_objects) subordinate_object->show_object_tree(depth + 1);
}

void cl_base::show_traversal_tree(int depth)
{
	std::cout << std::endl << std::string(depth * 4, ' ') << s_object_name << " is " << (i_object_state == 0?"not ":"") << "ready";
	for (cl_base* subordinate_object : subordinate_objects) subordinate_object->show_traversal_tree(depth + 1);
}