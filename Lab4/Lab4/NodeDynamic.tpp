template <typename T>
NodeDynamic<T>::NodeDynamic() :
	//val(NULL),
	parent(NULL)
{}

template <typename T>
NodeDynamic<T>::~NodeDynamic()
{
	for (int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
	std::cout << " Deleted: " << val << std::endl;
}

template <typename T>
void NodeDynamic<T>::set_value(T new_val)
{
	val = new_val;
}

template <typename T>
int NodeDynamic<T>::get_children_number()
{
	return children.size();
}

template <typename T>
void NodeDynamic<T>::add_new_child()
{
	NodeDynamic<T>* child = new NodeDynamic<T>();
	child->parent = this;
	children.push_back(child);
}

template <typename T>
void NodeDynamic<T>::add_new_child(NodeDynamic<T>* new_child)
{
	children.push_back(new_child);
	new_child->parent = this;
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::get_child(int child_offset)
{
	if (child_offset < 0 || children.size() <= child_offset)
	{
		return NULL;
	}
	return children[child_offset];
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::get_parent()
{
	return parent;
}

template <typename T>
bool NodeDynamic<T>::is_consistent()
{
	bool res = true;
	for (int i = 0; i < children.size(); i++)
	{
		res = res && (children[i]->parent == this);
	}
	return res;
}

template <typename T>
bool NodeDynamic<T>::all_consistent()
{
	if (!this->is_consistent())
	{
		return false;
	}
	bool res = true;
	for (int i = 0; i < children.size(); i++)
	{
		res = res && children[i]->all_consistent();
	}
	return res;
}

template <typename T>
void NodeDynamic<T>::print()
{
	std::cout << " " << val;
}

template <typename T>
void NodeDynamic<T>::print_all_below()
{
	print_children_below();
	std::cout << std::endl;
}

template <typename T>
void NodeDynamic<T>::print_children_below()
{
	print();
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->print_children_below();
	}
}

template <typename T>
bool NodeDynamic<T>::remove_child(NodeDynamic<T>* child)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i] == child)
		{
			children.erase(children.begin() + i);
			return true;
		}
	}
	return false;
}


// boolean specialisation
template <>
void NodeDynamic<bool>::print()
{
	std::cout << std::boolalpha << " " << val;
}