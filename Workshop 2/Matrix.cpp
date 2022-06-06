#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() //creates zero matrix
{
	rows = 3;
	columns = 3;
	elements = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = 0;
		}
	}

	objectCount += 1;
};
Matrix::Matrix(const int rows, const int columns, int r_range1, int r_range2) //generates random elements
{
	this->rows = rows;
	this->columns = columns;

	int r_range = abs(r_range1) + abs(r_range2);
	elements = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			elements[i][j] = r_range1 + rand() % (r_range + 1);
		}
	}

	objectCount += 1;
};
Matrix::Matrix(const int rows, const int columns, int** elements) : rows(rows), columns(columns), elements(elements) //creates object with predetermined elements
{
	objectCount += 1;
};
Matrix::Matrix(const Matrix& matrix) //copy constructor
{
	rows = matrix.rows;
	columns = matrix.columns;

	elements = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			this->elements[i][j] = matrix.elements[i][j];
		}
	}

	objectCount += 1;
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] elements[i];
	}

	delete[] elements;

	objectCount += 1;
}

Matrix Matrix::operator+(const Matrix& _m)
{
	Matrix m = Matrix::SumMatrices(*this, _m);
	return m;
}
Matrix Matrix::operator-(const Matrix& _m)
{
	Matrix m = Matrix::SubstructMatrices(*this, _m);
	return m;
}
Matrix Matrix::operator*(const Matrix& _m)
{
	Matrix m = Matrix::MultiplyMatrices(*this, _m);
	return m;
}
void Matrix::operator*=(const int& number) {
	Matrix m = MultiplyMatrixByNumber(*this, number);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = m.elements[i][j];
		}
	}
}
bool Matrix::operator==(const Matrix& _m)
{
	return CompareMatrices(*this, _m);
}

int Matrix::getRows()
{
	return(rows);
}
void Matrix::setRows(int rows)
{
	this->rows = rows;
}
int Matrix::getColumns()
{
	return(columns);
}
void Matrix::setColumns(int columns)
{
	this->columns = columns;
}
int** Matrix::getMatrix()
{
	return (elements);
}
void Matrix::setMatrix(int** elements)
{
	this->elements = elements;
}
int Matrix::getObjectCount()
{
	return objectCount;
}

void Matrix::printMatrix(const Matrix& matrix)
{
	int** elements = matrix.elements;
	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.columns; j++)
		{
			cout << elements[i][j] << "\t";
		}
		cout << endl;
	}
}
Matrix Matrix::SumMatrices(const Matrix& m1, const Matrix& m2)
{
	//works only when matrices have the same size (you cannot make matrices with different size in this application)
	int rows = m1.rows;
	int columns = m1.columns;

	int** elements = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = m1.elements[i][j] + m2.elements[i][j];
		}
	}

	Matrix m = Matrix(rows, columns, elements);
	return m;
}
Matrix Matrix::SubstructMatrices(const Matrix& m1, const Matrix& m2)
{
	//works only when matrices have the same size (you cannot make matrices with different size in this application)
	int rows = m1.rows;
	int columns = m1.columns;

	int** elements = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		elements[i] = new int[columns];
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = m1.elements[i][j] - m2.elements[i][j];
		}
	}

	Matrix m = Matrix(rows, columns, elements);
	return m;
}
Matrix Matrix::MultiplyMatrices(const Matrix& m1, const Matrix& m2)
{
	if (m1.columns != m2.rows)
	{
		cout << "The multiplication is impossible. The first matrix columns amount is not equal to the second matrix rows amount." << endl;
		return Matrix();
	}
	else
	{
		int rows = m1.rows;
		int columns = m2.columns;

		int** elements = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			elements[i] = new int[columns];
			for (int j = 0; j < columns; j++)
			{
				elements[i][j] = m1.elements[i][j] + m2.elements[i][j];

				int value = 0;
				int col = 0;
				for (int row = 0; row < rows; row++)
				{
					value += m1.elements[i][col] * m2.elements[row][j];
					col++;
				}
				elements[i][j] = value;
			}
		}
		Matrix m = Matrix(rows, columns, elements);
		return m;
	}
}
Matrix Matrix::MultiplyMatrixByNumber(const Matrix& _m, int number)
{
	int m_rows = _m.rows;
	int m_columns = _m.columns;
	int** m_elements = new int* [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_elements[i] = new int[m_columns];
	}

	//multiplying
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			//we can multiply both matrices in one loop because their size is always the same
			m_elements[i][j] = _m.elements[i][j] * number;
		}
	}

	Matrix m = Matrix(m_rows, m_columns, m_elements);
	return m;
}
bool Matrix::CompareMatrices(const Matrix& m1, const Matrix& m2)
{
	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.columns; j++)
		{
			if (m1.elements[i][j] != m2.elements[i][j])
				return false;
		}
	}
	return true;
}

int Matrix::objectCount = 0;