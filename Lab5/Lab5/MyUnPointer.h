template <typename T>
class MyUnPointer
{
private:
	T* ptr;
public:
	MyUnPointer(T* ptr);
	// MyUniquePointer(const MyUniquePointer& other) = delete;				// 1
	MyUnPointer(MyUnPointer&& other);					// 2
	~MyUnPointer();											// 3
	// MyUniquePointer& operator=(const MyUniquePointer& other) = delete;	// 4
	MyUnPointer& operator=(MyUnPointer&& other);		// 5
	T& operator*();
	T* operator->();
};

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

