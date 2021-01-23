#include "tests.h"
#include "Matrix.h"
#include <iostream>
#include <exception>

using namespace MyAlgebra;

void test_reading_file()
{
	std::cout << "Matrix of ints" << std::endl;
	Matrix<int> mat1 = Matrix<int>::read_txt("matint.txt");
	mat1.display();
	std::cout << "Matrix of doubles" << std::endl;
	Matrix<double> mat2 = Matrix<double>::read_txt("matdob.txt");
	mat2.display();
	std::cout << "Matrix of floats" << std::endl;
	Matrix<float> mat3 = Matrix<float>::read_txt("matflo.txt");
	mat2.display();
	std::cout << "Incorrect matrix" << std::endl;
	try
	{
		Matrix<double> mat4 = Matrix<double>::read_txt("matbad.txt");
		mat2.display();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Matrix of unsupported type" << std::endl;
	try
	{
		Matrix<std::string> mat5 = Matrix<std::string>::read_txt("matflo.txt");
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_matmul()
{
	Matrix<int> matint1 = Matrix<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint1[i][j] = i;
		}
	}
	Matrix<int> matint2 = Matrix<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint2[i][j] = j;
		}
	}
	Matrix<int> matint3 = matint1 * matint2;
	std::cout << "Matint1: " << std::endl;
	matint1.display();
	std::cout << "Matint2: " << std::endl;
	matint2.display();
	std::cout << "Matint3: " << std::endl;
	matint3.display();

	// FLOATS

	Matrix<float> matflo1 = Matrix<float>(3, 2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matflo1[i][j] = i;
		}
	}
	Matrix<float> matflo2 = Matrix<float>(2, 3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matflo2[i][j] = j;
		}
	}
	Matrix<float> matflo3 = matflo1 * matflo2;
	std::cout << "Matflo1: " << std::endl;
	matflo1.display();
	std::cout << "Matflo2: " << std::endl;
	matflo2.display();
	std::cout << "Matflo3: " << std::endl;
	matflo3.display();

	// DOUBLES

	Matrix<double> matdo1 = Matrix<double>(3, 2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matdo1[i][j] = double(i);
		}
	}
	Matrix<double> matdo2 = Matrix<double>(2, 1);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matdo2[i][j] = double(j) - double(2);
		}
	}
	Matrix<double> matdo3 = matdo1 * matdo2;
	std::cout << "Matdo1: " << std::endl;
	matdo1.display();
	std::cout << "Matdo2: " << std::endl;
	matdo2.display();
	std::cout << "Matdo3: " << std::endl;
	matdo3.display();

	// INCORRECT DIMENSIONS!!!!!
	Matrix<int> matinc1 = Matrix<int>(7, 2);
	Matrix<int> matinc2 = Matrix<int>(7, 2);
	try
	{
		Matrix<int> matinc3 = matinc1 * matinc2;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_addiction()
{
	Matrix<int> matint1 = Matrix<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint1[i][j] = i;
		}
	}
	Matrix<int> matint2 = Matrix<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint2[i][j] = j;
		}
	}
	Matrix<int> matint3 = matint1 + matint2;
	std::cout << "Matint1: " << std::endl;
	matint1.display();
	std::cout << "Matint2: " << std::endl;
	matint2.display();
	std::cout << "Matint3: " << std::endl;
	matint3.display();

	// FLOATS

	Matrix<float> matflo1 = Matrix<float>(3, 2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matflo1[i][j] = i;
		}
	}
	Matrix<float> matflo2 = Matrix<float>(3, 2);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matflo2[i][j] = j;
		}
	}
	Matrix<float> matflo3 = matflo1 + matflo2;
	std::cout << "Matflo1: " << std::endl;
	matflo1.display();
	std::cout << "Matflo2: " << std::endl;
	matflo2.display();
	std::cout << "Matflo3: " << std::endl;
	matflo3.display();

	// DOUBLES

	Matrix<double> matdo1 = Matrix<double>(2, 1);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matdo1[i][j] = double(i);
		}
	}
	Matrix<double> matdo2 = Matrix<double>(2, 1);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matdo2[i][j] = double(j) - double(2);
		}
	}
	Matrix<double> matdo3 = matdo1 + matdo2;
	std::cout << "Matdo1: " << std::endl;
	matdo1.display();
	std::cout << "Matdo2: " << std::endl;
	matdo2.display();
	std::cout << "Matdo3: " << std::endl;
	matdo3.display();

	// INCORRECT DIMENSIONS!!!!!
	Matrix<int> matinc1 = Matrix<int>(7, 2);
	Matrix<int> matinc2 = Matrix<int>(7, 3);
	try
	{
		Matrix<int> matinc3 = matinc1 + matinc2;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "dupaprint" << std::endl;
}

void test_subtraction()
{
}

void test_getvectors()
{
}
