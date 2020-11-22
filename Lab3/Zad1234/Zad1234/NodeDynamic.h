#pragma once
#include <iostream>
#include <vector>


class NodeDynamic
{
private:
	int val;
	NodeDynamic* parent;
	std::vector<NodeDynamic*> children;
	void print_children_below();
public:
	NodeDynamic();
	~NodeDynamic();
	void set_value(int new_val);
	int get_children_number();
	void add_new_child();
	void add_new_child(NodeDynamic* child);
	bool remove_child(NodeDynamic* child);
	NodeDynamic* get_child(int child_offset);
	NodeDynamic* get_parent();
	void print();
	void print_all_below();
};