template <typename T>
MySmartPointer<T>::MySmartPointer(T* ptr) :
	ptr(ptr),
	refCounter(new RefCounter)
{
	std::cout << "New pointer: " << ptr << std::endl;
	refCounter->add();
}


template <typename T>
MySmartPointer<T>::MySmartPointer(const MySmartPointer& other)
{
	ptr = other.ptr;
	refCounter = other.refCounter;
	refCounter->add();
}


template <typename T>
MySmartPointer<T>::MySmartPointer(MySmartPointer&& other)
{
	std::cout << "Move constructor: " << std::endl;
	ptr = other.ptr;
	refCounter = other.refCounter;
	other.ptr = nullptr;
	other.refCounter = nullptr;
}


template <typename T>
MySmartPointer<T>::~MySmartPointer()
{
	if (refCounter != nullptr && refCounter->dec() == 0)
	{
		delete refCounter;
		delete ptr;
		std::cout << "Deleted pointer" << ptr << std::endl;
	}
}


template <typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(const MySmartPointer& other)
{
	if (&other != this)
	{
		if (refCounter != nullptr && refCounter->dec() == 0)
		{
			std::cout << "Deleted: " << ptr << std::endl;
			delete ptr;
			delete refCounter;
		}
		refCounter = other.refCounter;
		ptr = other.ptr;
		refCounter->add();
	}
	return *this;
}


template <typename T>
MySmartPointer<T>& MySmartPointer<T>::operator=(MySmartPointer&& other)
{
	std::cout << "Move operator" << std::endl;
	if (&other != this)
	{
		if (refCounter != nullptr && refCounter->dec() == 0)
		{
			std::cout << "Deleted: " << ptr << std::endl;
			delete ptr;
			delete refCounter;
		}
		refCounter = other.refCounter;
		ptr = other.ptr;
		other.refCounter = nullptr;
		other.ptr = nullptr;
	}
	return *this;
}


template <typename T>
T& MySmartPointer<T>::operator*()
{
	return (*ptr);
}

template <typename T>
T* MySmartPointer<T>::operator->()
{
	return ptr;
}