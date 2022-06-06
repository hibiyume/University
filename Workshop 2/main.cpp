#include <iostream>
#include <string>
#include <conio.h>
#include "Matrix.h"

using namespace std;

int main()
{
	srand(time(NULL));

	//initializing, filling and testing Matrix object with default contructor (without any parameters)
	Matrix m_default;
	m_default.setRows(3);
	m_default.setColumns(4);
	m_default.setMatrix(new int* [3]{
			new int[4] { 3, 4, 6, 9},
			new int[4] { 1, 5, 12, 19},
			new int[4] { 15, 2, -3, 1},
		});

	cout << "Printing the matrix created by default constructor" << endl;
	Matrix::printMatrix(m_default);


	//initializing and testing Matrix object created by parameterized constructor
	Matrix m_params = Matrix(3, 4, -15, 20);
	cout << "Printing the matrix created by parameterized constructor" << endl;
	Matrix::printMatrix(m_params);
	

	//initializing and testing Matrix object created by parameterized constructor with initialization list
	Matrix m_params_list = Matrix(3, 3, new int* [3]{
		new int[3]{ 1, 7, 2 },
		new int[3]{ 2, 2, 9 },
		new int[3]{ 6, 4, 5 },
		});
	cout << "Printing the matrix created by parameterized constructor with initialization list" << endl;
	Matrix::printMatrix(m_params_list);


	//initializing and testing Matrix object created by copy constructor
	Matrix m_copy = Matrix(m_params_list);
	cout << "Printing the matrix created by copy constructor (copied from previous matrix)" << endl;
	Matrix::printMatrix(m_copy);


	//testing other code
	cout << endl;
	cout << "\"Matrix-type\" objects count (stored in static class variable) - " << Matrix::getObjectCount() << endl;

	cout << endl;
	Matrix m_sum = m_default + m_params;
	cout << "Printing the sum of the first and second matrices using operator overloading" << endl;
	Matrix::printMatrix(m_sum);

	Matrix m_sub = m_default - m_params;
	cout << "Printing the substraction of the first and second matrices using operator overloading" << endl;
	Matrix::printMatrix(m_sub);

	Matrix m_mult = m_params_list * m_copy;
	cout << "Printing the multiplication of the matrix made by copy constructor and its source matrix using operator overloading" << endl;
	Matrix::printMatrix(m_mult);

	m_default *= 3;
	cout << "Printing the multiplication of the first matrix by 3 using operator overloading" << endl;
	Matrix::printMatrix(m_default);

	cout << "Printing the result of the comparison of the first and second matrices : ";
	if (m_default == m_params)
		cout << "They are equal" << endl;
	else
		cout << "They are not equal" << endl;

	cout << "Printing the result of the comparison of the matrix made by copy constructor and its source matrix : ";
	if (m_params_list == m_copy)
		cout << "They are equal" << endl;
	else
		cout << "They are not equal" << endl;
}
