#include "NodeDynamic.h"


NodeDynamic::NodeDynamic() :
	val(0),
	parent(NULL)
{}

NodeDynamic::~NodeDynamic()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
	std::cout << " Deleted: " << val << std::endl;
}

void NodeDynamic::set_value(int new_val)
{
	val = new_val;
}

int NodeDynamic::get_children_number()
{
	return children.size();
}

void NodeDynamic::add_new_child()
{
	NodeDynamic* child = new NodeDynamic();
	child->parent = this;
	children.push_back(child);
}

void NodeDynamic::add_new_child(NodeDynamic* new_child)
{
	children.push_back(new_child);
	new_child->parent = this;
}

NodeDynamic* NodeDynamic::get_child(int child_offset)
{
	if (child_offset < 0 || children.size() <= child_offset)
	{
		return NULL;
	}
	return children[child_offset];
}

NodeDynamic* NodeDynamic::get_parent()
{
	return parent;
}


void NodeDynamic::print()
{
	std::cout << " " << val;
}

void NodeDynamic::print_all_below()
{
	print_children_below();
	std::cout << std::endl;
}

void NodeDynamic::print_children_below()
{
	print();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->print_children_below();
	}
}

bool NodeDynamic::remove_child(NodeDynamic* child)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == child)
		{
			return true;
		}
	}
	return false;
}
