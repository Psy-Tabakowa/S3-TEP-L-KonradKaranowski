#include <iostream>
#include "NodeStatic.h"


NodeStatic::NodeStatic() :
	val(0),
	parent(NULL)
{}

NodeStatic::~NodeStatic()
{
	std::cout << "Usunieto: " << this << std::endl;
}

int NodeStatic::get_children_number()
{
	return children.size();
}

void NodeStatic::set_value(int new_val)
{
	val = new_val;
}

void NodeStatic::add_new_child()
{
	NodeStatic new_node;
	new_node.parent = this;
	children.push_back(new_node);
}

NodeStatic* NodeStatic::get_child(int child_offset)
{
	if (child_offset < 0 || child_offset >= children.size())
	{
		return NULL;
	}
	return &children[child_offset];
}

void NodeStatic::print()
{
	std::cout << " " << val;
}

void NodeStatic::print_all_below()
{
	print_children_below();
	std::cout << std::endl;

}

void NodeStatic::print_children_below()
{
	print();
	for (int i = 0; i < children.size(); i++)
	{
		children[i].print_children_below();
	}
}

void NodeStatic::print_up()
{
	print_up(this);
}

void NodeStatic::print_up(NodeStatic* node)
{
	if (node != NULL)
	{
		node->print();
		print_up(node->parent);
	}
	else
	{
		std::cout << std::endl;
	}
}

