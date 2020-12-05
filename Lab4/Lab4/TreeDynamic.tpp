template <typename T>
TreeDynamic<T>::TreeDynamic() :
	root(new NodeDynamic<T>)
{
}

template <typename T>
TreeDynamic<T>::~TreeDynamic()
{
	delete root;
}

template <typename T>
NodeDynamic<T>* TreeDynamic<T>::get_root()
{
	return root;
}

template <typename T>
void TreeDynamic<T>::print_tree()
{
	root->print_all_below();
}

template <typename T>
bool TreeDynamic<T>::move_subtree(NodeDynamic<T>* parent_node, NodeDynamic<T>* new_child_node)
{
	if (parent_node == NULL)
	{
		return false;
	}
	if (new_child_node != NULL)
	{
		NodeDynamic<T>* former_parent = new_child_node->get_parent();
		if (former_parent != NULL)
		{
			former_parent->remove_child(new_child_node);
		}
		parent_node->add_new_child(new_child_node);
	}
	return true;
}

template <typename T>
bool TreeDynamic<T>::is_consistent()
{
	return root->all_consistent();
}
