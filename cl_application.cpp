#include "cl_application.h"

cl_application::cl_application(cl_application* p_head_object, std::string s_object_name) : cl_base(p_head_object)
{
}

void cl_application::bild_tree_objects()
{
	int id;
	std::string head, sub;
	cl_base* last_head = this, * last_sub = nullptr;

	std::cin >> head;
	change_object_name(head);
	while (true)
	{
		std::cin >> head;
		if (head == "endtree") break;

		std::cin >> sub >> id;

		if (get_object_by_name(sub)) continue;

		last_head = get_object_by_name(head);
		if (id == 2) last_sub = new cl_base_2(last_head, sub);
		else if (id == 3) last_sub = new cl_base_3(last_head, sub);
		else if (id == 4) last_sub = new cl_base_4(last_head, sub);
		else if (id == 5) last_sub = new cl_base_5(last_head, sub);
		else if (id == 6) last_sub = new cl_base_6(last_head, sub);
	}

	std::getline(std::cin, head, '\n');
	while (true)
	{
		std::getline(std::cin, head, '\n');
		if (head.empty()) break;
		
		get_object_by_name(head.substr(0, head.find(' ')))->change_object_state(atoi(head.substr(head.find(' ') + 1).c_str()));
	}
}

int cl_application::exec_app()
{
	std::cout << "Object tree";
	show_object_tree();
	std::cout << std::endl << "The tree of objects and their readiness";
	show_traversal_tree();

	return 0;
}