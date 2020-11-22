#pragma once
#include <iostream>
#include <vector>


class NodeStatic
{
private:
	int val;
	NodeStatic* parent;
	std::vector<NodeStatic> children;
	void print_up(NodeStatic* node);
	void print_children_below();
public:
	NodeStatic();
	~NodeStatic();
	int get_children_number();
	void set_value(int new_val);
	void add_new_child();
	NodeStatic* get_child(int child_offset);
	void print();
	void print_all_below();
	void print_up();
};