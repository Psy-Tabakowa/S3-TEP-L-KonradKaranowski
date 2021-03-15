#include "tests.h"
#include "Matrix.h"
#include <iostream>
#include <exception>

using namespace MyAlgebra;

void test_reading_file()
{
	std::cout << "Matrix of ints" << std::endl;
	Matrix<int> mat1 = Matrix<int>::read_txt("matint.txt", ';');
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
	Matrix<int> vecint1 = Matrix<int>(1, 12);
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			vecint1[i][j] = i - 2 * j;
		}
	}
	Matrix<int> vecint2 = vecint1 * ~vecint1;
	std::cout << "Vecint: " << std::endl;
	vecint1.display();
	std::cout << "Vecint * vecint transposed: " << std::endl;
	vecint2.display();



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
		for (int j = 0; j < 2; j++)
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
	Matrix<int> matint3 = matint1 - matint2;
	std::cout << "Matint1: " << std::endl;
	matint1.display();
	std::cout << "Matint2: " << std::endl;
	matint2.display();
	std::cout << "Matint3: " << std::endl;
	matint3.display();

	//// FLOATS

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
		for (int j = 0; j < 2; j++)
		{
			matflo2[i][j] = j;
		}
	}
	Matrix<float> matflo3 = matflo1 - matflo2;
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
	Matrix<double> matdo3 = matdo1 - matdo2;
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
		Matrix<int> matinc3 = matinc1 - matinc2;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_getvectors()
{
	Matrix<int> matint1 = Matrix<int>(2, 3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint1[i][j] = i + j;
		}
	}
	Matrix<int> row1 = matint1.row_vector(0);
	Matrix<int> col2 = matint1.col_vector(1);
	Matrix<int> col_row1 = row1.col_vector(2);
	std::cout << "Matint 1: " << std::endl;
	matint1.display();
	std::cout << "Row 0: " << std::endl;
	row1.display();
	std::cout << "Col 1: " << std::endl;
	col2.display();
	std::cout << "Col row2: " << std::endl;
	col_row1.display();
}

void test_scalar()
{
	Matrix<int> matint1 = Matrix<int>(3, 3);
	matint1 = 2;
	Matrix<int> matint2 = Matrix<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint2[i][j] = j;
		}
	}
	Matrix<int> matint3 = matint1 * 2;
	Matrix<int> matint4 = 2 * matint2;
	std::cout << "Matint1: " << std::endl;
	matint1.display();
	std::cout << "Matint2: " << std::endl;
	matint2.display();
	std::cout << "Matint3: " << std::endl;
	matint3.display();
	std::cout << "Matint4: " << std::endl;
	matint4.display();

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
		for (int j = 0; j < 2; j++)
		{
			matflo2[i][j] = j;
		}
	}
	Matrix<float> matflo3 = matflo1 * 1.1;
	Matrix<float> matflo4 = -1.f * matflo2;
	std::cout << "Matflo1: " << std::endl;
	matflo1.display();
	std::cout << "Matflo2: " << std::endl;
	matflo2.display();
	std::cout << "Matflo3: " << std::endl;
	matflo3.display();
	std::cout << "Matflo4: " << std::endl;
	matflo4.display();

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
	Matrix<double> matdo3 = matdo1 * 100;
	Matrix<double> matdo4 = -2.0 * matdo2 * 100;
	std::cout << "Matdo1: " << std::endl;
	matdo1.display();
	std::cout << "Matdo2: " << std::endl;
	matdo2.display();
	std::cout << "Matdo3: " << std::endl;
	matdo3.display();
	std::cout << "Matdo4: " << std::endl;
	matdo4.display();
}

void test_dotproduct()
{
	Matrix<int> matint1 = Matrix<int>(3, 1);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matint1[i][j] = i;
		}
	}
	Matrix<int> matint2 = Matrix<int>(1, 3);
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint2[i][j] = j;
		}
	}
	int product_int = matint1 | matint2;
	std::cout << "Matint1: " << std::endl;
	matint1.display();
	std::cout << "Matint2: " << std::endl;
	matint2.display();
	std::cout << "Product_int: " << product_int << std::endl;

	//// FLOATS

	Matrix<float> matflo1 = Matrix<float>(3, 1);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matflo1[i][j] = i;
		}
	}
	Matrix<float> matflo2 = Matrix<float>(3, 1);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			matflo2[i][j] = j - i;
		}
	}
	float product_float = matflo1 | matflo2;
	std::cout << "Matflo1: " << std::endl;
	matflo1.display();
	std::cout << "Matflo2: " << std::endl;
	matflo2.display();
	std::cout << "Product float: " << product_float << std::endl;

	// DOUBLES

	Matrix<double> matdo1 = Matrix<double>(1, 2);
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matdo1[i][j] = double(i + j);
		}
	}
	Matrix<double> matdo2 = Matrix<double>(1, 2);
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matdo2[i][j] = double(j) - double(2);
		}
	}
	double product_double = matdo1 | matdo2;
	std::cout << "Matdo1: " << std::endl;
	matdo1.display();
	std::cout << "Matdo2: " << std::endl;
	matdo2.display();
	std::cout << "Product double: " << product_double << std::endl;

	// INCORRECT DIMENSIONS!!!!!
	Matrix<int> matinc1 = Matrix<int>(5, 1);
	Matrix<int> matinc2 = Matrix<int>(6, 1);
	try
	{
		int invalid1 = matinc1 | matinc2;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	Matrix<int> matinc3 = Matrix<int>(5, 2);
	Matrix<int> matinc4 = Matrix<int>(2, 1);
	try
	{
		int invalid2 = matinc1 | matinc2;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_transpose()
{
	Matrix<int> matint = Matrix<int>(5, 3);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matint[i][j] = j * i;
		}
	}
	Matrix<int> mattrans = ~matint;
	std::cout << "Matrix: " << std::endl;
	matint.display();
	std::cout << "Matrix transposed: " << std::endl;
	mattrans.display();
}

void test_save()
{
	Matrix<int> mt1 = Matrix<int>(2, 3);
	for (int i = 0; i < 2; i++)
	{
		for (int j=0; j<3; j++)
		{
			mt1[i][j] = i + j;
		}
	}
	mt1.display();
	bool r1 = mt1.save_txt("supermacierz.txt");
	bool r2 = mt1.save_txt("POTEMNSZNA MAMCIEMSZ.txt", "===");
	std::cout << r1 << " " << r2 << std::endl;
	Matrix<float> mt2 = Matrix<float>(2, 3);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mt2[i][j] = i + j + 0.5f;
		}
	}
	mt2.display();
	bool rt1 = mt2.save_txt("supermacierz2.txt");
	bool rt2 = mt2.save_txt("POTEMNSZNA MAMCIEMSZ2.txt", "^^^");
	std::cout << rt1 << " " << rt2 << std::endl;
}