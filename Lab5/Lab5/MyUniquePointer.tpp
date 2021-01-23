
template<typename T>
MyUnPointer<T>::MyUnPointer(T* ptr) :
	ptr(ptr)
{
	std::cout << "New ptr: " << ptr << std::endl;
}


template<typename T>
MyUnPointer<T>::MyUnPointer(MyUnPointer&& other)
{
	std::cout << "Move operator" << std::endl;
	if (&other != this)
	{
		std::cout << "Deleted: " << ptr << std::endl;
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

template<typename T>
MyUnPointer<T>::~MyUnPointer()
{
	delete ptr;
}


template<typename T>
T& MyUnPointer<T>::operator*()
{
	return *ptr;
}

template<typename T>
T* MyUnPointer<T>::operator->()
{
	return ptr;
}

