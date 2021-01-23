#pragma once
#include <iostream>
#include "RefCounter.h"


template <typename T>
class MySmartPointer
{
private:
	T* ptr;
	RefCounter* refCounter;
public:
	MySmartPointer(T* ptr);
	MySmartPointer(const MySmartPointer& other);			// 1
	MySmartPointer(MySmartPointer&& other);					// 2
	~MySmartPointer();										// 3
	MySmartPointer& operator=(const MySmartPointer& other); // 4
	MySmartPointer& operator=(MySmartPointer&& other);		// 5
	T& operator*();
	T* operator->();
};
	
#include "MySmartPointer.tpp"