#include "NodeStatic.h"
#include "TreeStatic.h"
#include "NodeDynamic.h"
#include "TreeDynamic.h"


void static_nodes_test()
{
	NodeStatic root;
	root.add_new_child();
	root.add_new_child();

	root.get_child(0)->set_value(1);
	root.get_child(1)->set_value(2);

	root.get_child(0)->add_new_child();
	root.get_child(0)->add_new_child();

	root.get_child(0)->get_child(0)->set_value(11);
	root.get_child(0)->get_child(1)->set_value(12);

	root.get_child(1)->add_new_child();
	root.get_child(1)->add_new_child();

	root.get_child(1)->get_child(0)->set_value(21);
	root.get_child(1)->get_child(1)->set_value(22);

	std::cout << "Print all bellow: ";
	root.print_all_below();

	std::cout << "Print up: ";
	root.get_child(0)->get_child(1)->print_up();
}


void static_tree_test()
{
	TreeStatic tree;
	std::cout << "Print Tree: ";
	tree.print_tree();
}


void dynamic_nodes_test()
{
	NodeDynamic root;

	root.add_new_child();
	root.add_new_child();

	root.get_child(0)->set_value(1);
	root.get_child(1)->set_value(2);

	root.get_child(0)->add_new_child();
	root.get_child(0)->add_new_child();

	root.get_child(0)->get_child(0)->set_value(11);
	root.get_child(0)->get_child(1)->set_value(12);

	root.get_child(1)->add_new_child();
	root.get_child(1)->add_new_child();

	root.get_child(1)->get_child(0)->set_value(21);
	root.get_child(1)->get_child(1)->set_value(22);

	std::cout << "Print all bellow: ";
	root.print_all_below();
}


void dynamic_tree_test()
{
	TreeDynamic tree;
	std::cout << "Print Tree: ";
	tree.print_tree();
}


void move_subtree_test()
{
	TreeDynamic tree1;
	TreeDynamic tree2;
	tree1.get_root()->add_new_child();
	tree1.get_root()->add_new_child();
	tree1.get_root()->get_child(0)->set_value(3);
	tree1.get_root()->get_child(1)->set_value(5);
	tree1.get_root()->print_all_below();

	NodeDynamic* root2 = new NodeDynamic();
	tree2.get_root()->add_new_child();
	tree2.get_root()->add_new_child();
	tree2.get_root()->get_child(0)->set_value(-5);
	tree2.get_root()->get_child(1)->set_value(-3);
	tree2.get_root()->print_all_below();

	bool result = tree1.move_subtree(tree1.get_root(), tree2.get_root()->get_child(0));
	std::cout << std::boolalpha << result << std::endl;
	tree1.get_root()->print_all_below();
	tree2.get_root()->print_all_below();
}