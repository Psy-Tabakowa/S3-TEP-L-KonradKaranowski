#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>



namespace MyAlgebra
{
	const char SEP = ' ';
	template <typename T>
	class Matrix
	{
	private:
		T* matrix;
		int rows;
		int cols;
		int elements;
	public:
		Matrix(uint16_t rows, uint16_t cols, T* matrix);
		// some dumb matrix
		Matrix(uint16_t rows, uint16_t cols);
		// copy constructor
		Matrix(const Matrix& other);
		// move constructor
		Matrix(Matrix&& other);
		// delete this
		~Matrix();

		// copy assignment
		Matrix& operator=(const Matrix& other);
		// move assignment
		Matrix& operator=(Matrix&& other);
		// diagonal matrix
		// diagonal matrix
		Matrix& operator=(T* diagonal);

		// coœ tam coœ tam
		T* operator[](int idx);

		// transposition
		Matrix operator~();
		// add and subt
		Matrix operator+(const Matrix& other);
		Matrix operator-(const Matrix& other);
		// matmul
		Matrix operator*(const Matrix& other);
		// mul by scalar
		Matrix operator*(T scalar);
		// vector dot product
		T operator|(const Matrix& other);

		// some random vectors
		Matrix rowVector(int idx);
		Matrix colVector(int idx);

		// print matrix
		void display();

		// read from file
		static Matrix<T> read_txt(const std::string& path);

		// conversions
		static T convert(const std::string& string);
	};
}

template<typename T>
MyAlgebra::Matrix<T>::Matrix(uint16_t rows, uint16_t cols, T* matrix) :
	rows(rows),
	cols(cols),
	elements(rows * cols),
	matrix(matrix)
{
}

template<typename T>
MyAlgebra::Matrix<T>::Matrix(uint16_t rows, uint16_t cols) :
	rows(rows),
	cols(cols),
	elements(rows * cols)
{
	matrix = new T[elements];
}

template<typename T>
MyAlgebra::Matrix<T>::Matrix(const Matrix& other) :
	rows(other.rows),
	cols(other.cols),
	elements(other.elements)
{
	matrix = new T[elements];
	for (int i = 0; i < elements; i++)
	{
		matrix[i] = other.matrix[i];
	}
}

template<typename T>
MyAlgebra::Matrix<T>::Matrix(Matrix&& other) :
	rows(other.rows),
	cols(other.cols),
	elements(other.elements),
	matrix(other.matrix)
{
	other.rows = 0;
	other.cols = 0;
	other.elements = 0;
	other.matrix = nullptr;
}

template<typename T>
MyAlgebra::Matrix<T>::~Matrix()
{
	std::cout << "delete this" << std::endl;
	delete[] matrix;
}

template<typename T>
MyAlgebra::Matrix<T>& MyAlgebra::Matrix<T>::operator=(const Matrix& other)
{
	if (&other != this)
	{
		delete[] matrix;
		matrix = new T[other.elements];
		for (int i = 0; i < other.elements; i++)
		{
			matrix[i] = other.matrix[i];
		}
		rows = other.rows;
		cols = other.cols;
		elements = other.elements;
	}
	return this;
}

template<typename T>
MyAlgebra::Matrix<T>& MyAlgebra::Matrix<T>::operator=(Matrix&& other)
{
	if (&other != this)
	{
		delete[] matrix;
		matrix = other.matrix;
		rows = other.rows;
		cols = other.cols;
		elements = other.elements;

		other.rows = 0;
		other.cols = 0;
		other.elements = 0;
		other.matrix = nullptr;
	}
}

template<typename T>
MyAlgebra::Matrix<T>& MyAlgebra::Matrix<T>::operator=(T* diagonal)
{
	if (rows != cols)
	{
		throw std::exception("Matrix is not square.");
	}
	int diagonal_idx = 0;
	for (int i = 0; i < elements; i++)
	{
		if (i == diagonal_idx)
		{
			matrix[i] = diagonal;
			diagonal_idx += rows + 1;
		}
		else
		{
			matrix[i] = T();
		}
	}
	return *this;
}

template<typename T>
T* MyAlgebra::Matrix<T>::operator[](int idx)
{
	if (idx < 0 || idx > rows)
	{
		throw std::exception("Invalid index");
	}
	return &matrix[idx * cols];
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::operator~()
{
	T* new_matrix = new T[elements];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			new_matrix[j * rows + i] = matrix[i * cols + j];
		}
	}
	return Matrix(rows, cols, new_matrix);
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::operator+(const Matrix& other)
{
	if (cols != other.cols || rows != other.rows)
	{
		throw std::exception("Invalid matrices");
	}
	T* new_matrix = new T[elements];
	for (int i = 0; i < elements; i++)
	{
		new_matrix[i] = matrix[i] + other.matrix[i];
	}
	return Matrix(rows, cols, new_matrix);
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::operator-(const Matrix& other)
{
	if (cols != other.cols || rows != other.rows)
	{
		throw std::exception("Invalid matrices");
	}
	T* new_matrix = new T[elements];
	for (int i = 0; i < elements; i++)
	{
		new_matrix[i] = matrix[i] - other.matrix[i];
	}
	return Matrix(rows, cols, new_matrix);
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::operator*(const Matrix& other)
{
	if (cols != other.rows)
	{
		throw std::exception("Invalid dimensions");
	}
	T* new_matrix = new T[rows * other.cols];
	// nie dzia³a³o mi fill_n -.-
	for (int i = 0; i < rows * other.cols; i++)
	{
		new_matrix[i] = T{};
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int k = 0; k < other.cols; k++)
			{
				new_matrix[i * other.cols + k] += matrix[i * cols + j] * other.matrix[j * other.cols + k];
			}
		}
	}
	return Matrix(rows, other.cols, new_matrix);
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::operator*(T scalar)
{
	T new_matrix = new T[elements];
	for (int i = 0; i < elements; i++)
	{
		new_matrix[i] = matrix[i] * scalar;
	}
	return Matrix(rows, cols, new_matrix);
}

template<typename T>
T MyAlgebra::Matrix<T>::operator|(const Matrix& other)
{
	if ((cols > 1 && rows > 1) || (other.rows > 1 || other.cols > 1))
	{
		throw std::exception("This vectors are not vectors.");
	}
	if (elements != other.elements)
	{
		throw std::exception("Cannot multiply two vectors of not equal lenghts.");
	}
	T product = T();
	for (int i = 0; i < elements; i++)
	{
		product += matrix[i] * other.matrix[i];
	}
	return product;
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::rowVector(int idx)
{
	if (idx < 0 || idx > rows)
	{
		throw std::exception("Invalid index.");
	}
	T* new_matrix = new T[cols];
	for (int i = 0; i < cols; i++)
	{
		new_matrix[i] = matrix[i * cols + cols];
	}
	return Matrix(1, cols, new_matrix);
}


template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::colVector(int idx)
{
	if (idx < 0 || idx > cols)
	{
		throw std::exception("Invalid index.");
	}
	T* new_matrix = new T[cols];
	for (int i = 0; i < rows; i++)
	{
		new_matrix[i] = matrix[i * rows + rows];
	}
	return Matrix(rows, 1, new_matrix);
}

template<typename T>
MyAlgebra::Matrix<T> MyAlgebra::Matrix<T>::read_txt(const std::string& path)
{	
	std::ifstream file;
	file.open(path);
	if (!file.good())
	{
		throw std::exception("Couldn't open the file. Maybe reboot or something?");
	}
	std::vector<std::string> matrix;
	std::string current_line;
	while (std::getline(file, current_line))
	{
		matrix.push_back(current_line);
	}
	file.close();
	int rows = matrix.size();
	int cols = 0;
	// ale mi siê nie chce jezus maria
	std::string temp;
	std::stringstream stream = std::stringstream(matrix[0]);
	while (getline(stream, temp, SEP))
	{
		cols++;
	}
	T* new_matrix = new T[rows * cols];
	for (int i = 0; i < rows; i++)
	{
		std::vector<T> vector;
		std::string temp;
		std::stringstream stream = std::stringstream(matrix[i]);
		while (getline(stream, temp, SEP))
		{
			vector.push_back(convert(temp));
		}
		if (vector.size() != cols)
		{
			throw std::exception("This is not correct matrix in txt format.");
		}
		for (int j = 0; j < cols; j++)
		{
			new_matrix[i * cols + j] = vector[j];
		}
	}
	return Matrix<T>(rows, cols, new_matrix);
}

// conversions
template <typename T>
T MyAlgebra::Matrix<T>::convert(const std::string& string)
{
	throw std::exception("This type is not supported.");
}

template <>
inline int MyAlgebra::Matrix<int>::convert(const std::string& string)
{
	return std::stoi(string);
}

template <>
inline double MyAlgebra::Matrix<double>::convert(const std::string& string)
{
	return std::stod(string);
}

template <>
inline float MyAlgebra::Matrix<float>::convert(const std::string& string)
{
	return std::stof(string);
}


template <typename T>
void MyAlgebra::Matrix<T>::display()
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i * cols + j] << ", ";
		}
		std::cout << '|' << std::endl;
	}
}

