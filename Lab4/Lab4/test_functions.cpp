#include "TreeDynamic.h"
#include <string>


void test_string()
{
	TreeDynamic<std::string> tree = TreeDynamic<std::string>();
	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->set_value("Paczek ");
	tree.get_root()->get_child(0)->set_value("z lukrem ");
	tree.get_root()->get_child(1)->set_value("syntaktycznym.");

	tree.print_tree();
	tree.get_root()->remove_child(tree.get_root()->get_child(1));
	tree.print_tree();
}


void test_int()
{
	TreeDynamic<int> tree = TreeDynamic<int>();
	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->set_value(0);
	tree.get_root()->get_child(0)->set_value(1);
	tree.get_root()->get_child(1)->set_value(2);
	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(3);

	tree.print_tree();

	tree.get_root()->remove_child(tree.get_root()->get_child(0));
	tree.print_tree();
}


void test_int_pointer()
{
	int *p1, *p2, *p3;
	p1 = new int;
	p2 = new int;
	p3 = new int;

	TreeDynamic<int*> tree = TreeDynamic<int*>();

	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->set_value(0);
	tree.get_root()->get_child(0)->set_value(p1);
	tree.get_root()->get_child(1)->set_value(p2);
	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(p3);

	tree.print_tree();
	
	delete p1, p2, p3;
}


void test_bool()
{
	TreeDynamic<bool> tree = TreeDynamic<bool>();
	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->set_value(0);
	tree.get_root()->get_child(0)->set_value(1);
	tree.get_root()->get_child(1)->set_value(2);
	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(3);

	tree.print_tree();

	tree.get_root()->remove_child(tree.get_root()->get_child(0));
	tree.print_tree();
}


void test_is_consistent()
{
	TreeDynamic<bool> tree = TreeDynamic<bool>();
	tree.get_root()->add_new_child();
	tree.get_root()->add_new_child();

	tree.get_root()->set_value(0);
	tree.get_root()->get_child(0)->set_value(1);
	tree.get_root()->get_child(1)->set_value(2);
	tree.get_root()->get_child(0)->add_new_child();
	tree.get_root()->get_child(0)->get_child(0)->set_value(3);

	std::cout << "Tree consistent: " << std::boolalpha << tree.is_consistent() << std::endl;
}
