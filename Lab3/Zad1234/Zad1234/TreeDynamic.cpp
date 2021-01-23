#include "TreeDynamic.h"

TreeDynamic::TreeDynamic() :
	root(new NodeDynamic)
{
}

TreeDynamic::~TreeDynamic()
{
	delete root;
}

NodeDynamic* TreeDynamic::get_root()
{
	return root;
}

void TreeDynamic::print_tree()
{
	root->print_all_below();
}

bool TreeDynamic::move_subtree(NodeDynamic* parent_node, NodeDynamic* new_child_node)
{
	if (parent_node == NULL)
	{
		return false;
	}
	if (new_child_node != NULL)
	{
		NodeDynamic* former_parent = new_child_node->get_parent();
		if (former_parent != NULL)
		{
			former_parent->remove_child(new_child_node);
		}
	}
	parent_node->add_new_child(new_child_node);
	return true;
}

