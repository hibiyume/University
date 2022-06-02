#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Matrix
{
	private:
		int rows, columns;
		int** elements;
	public:
		int getRows()
		{
			return(rows);
		}
		void setRows(int rows)
		{
			this->rows = rows;
		}
		int getColumns()
		{
			return(columns);
		}
		void setColumns(int columns)
		{
			this->columns = columns;
		}
		int** getMatrix()
		{
			return (elements);
		}
		int getElement(int row, int column)
		{
			return(elements[row][column]);
		}
		void setElement(int row, int column, int value)
		{
			elements[row][column] = value;
		}


		void setRandomMatrix(int range1, int range2) {
			elements = new int*[rows];
			for (int i = 0; i < rows; i++)
			{
				elements[i] = new int[columns];
			}

			int range = abs(range1) + abs(range2);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					elements[i][j] = range1 + rand() % (range + 1);
				}
			}
		}
		void setAlmostRandomMatrix(int range1, int range2, Matrix* m) {
			int p = 1 + rand() % 101;
			//generating the same matrix
			if (p <= 33)
			{
				elements = new int* [rows];
				for (int i = 0; i < rows; i++)
				{
					elements[i] = new int[columns];
				}

				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < columns; j++) {
						elements[i][j] = m->getElement(i, j);
					}
				}
			}
			else
			{
				elements = new int* [rows];
				for (int i = 0; i < rows; i++)
				{
					elements[i] = new int[columns];
				}

				int range = abs(range1) + abs(range2);
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < columns; j++) {
						elements[i][j] = range1 + rand() % (range + 1);
					}
				}
			}
		}
		void setZeroMatrix(int rows, int columns)
		{
			elements = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				elements[i] = new int[columns];
			}

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					elements[i][j] = 0;
				}
			}
		}

		static void printMatrix(Matrix* matrix)
		{
			int** elements = matrix->getMatrix();
			for (int i = 0; i < matrix->getRows(); i++)
			{
				for (int j = 0; j < matrix->getColumns(); j++)
				{
					cout << elements[i][j] << "\t";
				}
				cout << endl;
			}
		}
		static Matrix* SumMatrices(Matrix* m1, Matrix* m2)
		{
			Matrix* m = new Matrix();
			m->setRows(m1->getRows());
			m->setColumns(m1->getColumns());

			m->setZeroMatrix(m1->getRows(), m2->getColumns());

			//works only when matrices have the same size (you cannot make matrices with different size in this application)
			for (int i = 0; i < m1->getRows(); i++)
			{
				for (int j = 0; j < m1->getColumns(); j++)
				{
					m->setElement(i, j, m1->getElement(i, j) + m2->getElement(i, j));
				}
			}

			return m;
		}
		static Matrix* MultiplyMatrices(Matrix* m1, Matrix* m2)
		{
			Matrix* m = new Matrix();
			m->setRows(m1->getRows());
			m->setColumns(m2->getColumns());

			m->setZeroMatrix(m1->getRows(), m2->getColumns());

			for (int i = 0; i < m->getRows(); i++)
			{
				for (int j = 0; j < m->getColumns(); j++)
				{
					int value = 0;
					int col = 0;
					for (int row = 0; row < m1->getRows(); row++)
					{
						value += m1->getElement(i, col) * m2->getElement(row, j);

						col++;
					}
					m->setElement(i, j, value);
				}
			}

			return m;
		}
		static Matrix** MultiplyMatricesByNumber(Matrix* m1, Matrix* m2, int number)
		{
			Matrix** m = new Matrix*[2];
			m[0] = new Matrix();
			m[1] = new Matrix();

			m[0]->setRows(m1->getRows());
			m[0]->setColumns(m1->getColumns());
			m[1]->setRows(m2->getRows());
			m[1]->setColumns(m2->getColumns());

			m[0]->setZeroMatrix(m1->getRows(), m1->getColumns());
			m[1]->setZeroMatrix(m2->getRows(), m2->getColumns());

			for (int i = 0; i < m1->getRows(); i++)
			{
				for (int j = 0; j < m1->getColumns(); j++)
				{
					//we can multiplay both matrices in one loop because their size is always the same
					m[0]->setElement(i, j, m1->getElement(i, j) * number);
					m[1]->setElement(i, j, m2->getElement(i, j) * number);
				}
			}

			return m;
		}
		static bool CompareMatrices(Matrix* m1, Matrix* m2)
		{
			for (int i = 0; i < m1->getRows(); i++)
			{
				for (int j = 0; j < m1->getColumns(); j++)
				{
					if (m1->getElement(i, j) != m2->getElement(i, j))
						return false;
				}
			}
			return true;
		}
		static void printMenu(Matrix* m1, Matrix* m2)
		{
			system("cls");
			cout << "Matrix #1 " << m1->getRows() << "x" << m1->getColumns() << " with random numbers" << endl;
			printMatrix(m1);
			cout << endl;
			cout << "Matrix #2 " << m2->getRows() << "x" << m2->getColumns() << " with random numbers" << endl;
			printMatrix(m2);
			cout << endl;

			cout << "Select any key to continue." << endl << endl;
			cout << "1 - Sum these matrices" << endl;
			cout << "2 - Multiply these matrices" << endl;
			cout << "3 - Multiply these matrices by a number" << endl;
			cout << "4 - Compare these matrices" << endl;
			cout << "5 - Close program" << endl;
		}
};

int main()
{
	srand(time(NULL));

	Matrix* m1 = new Matrix();
	Matrix* m2 = new Matrix();

	int rows, columns;
	cout << "Enter the number of rows : ";
	cin >> rows;
	cout << "Enter the number of columns : ";
	cin >> columns;

	m1->setRows(rows);
	m2->setRows(rows);
	m1->setColumns(columns);
	m2->setColumns(columns);

	// Note: setAlmostRandomMatrix() function has 33 % chance to generate equal
	//       matrices to demonstrate the work of the matrix equality function
	m1->setRandomMatrix(-10, 20);
	m2->setAlmostRandomMatrix(-10, 20, m1);
	Matrix::printMenu(m1, m2);

	int option = 0;
	while (option != 5) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> option;
		switch (option) {
		case 1:
		{
			Matrix* m = new Matrix();

			m = Matrix::SumMatrices(m1, m2);

			cout << endl;
			cout << "The sum of matrices" << endl;
			Matrix::printMatrix(m);

			delete m;

			cout << "Enter any key to continue" << endl;
			_getch(); //reads a key without writing it and pressing enter
			system("cls");
			Matrix::printMenu(m1, m2);
		}
			break;
		case 2:
		{
			Matrix* m = new Matrix();

			m = Matrix::MultiplyMatrices(m1, m2);

			cout << endl;
			cout << "The multiplication of matrices" << endl;
			Matrix::printMatrix(m);

			delete m;

			cout << "Enter any key to continue" << endl;
			_getch(); //reads a key without writing it and pressing enter
			system("cls");
			Matrix::printMenu(m1, m2);
		}
			break;
		case 3:
		{
			Matrix** matrices = new Matrix*();

			int number;
			cout << "Enter the number" << endl;
			cin >> number;

			matrices = Matrix::MultiplyMatricesByNumber(m1, m2, number);

			cout << endl;
			cout << "The matrix #1" << endl;
			Matrix::printMatrix(matrices[0]);

			cout << endl;
			cout << "The matrix #2" << endl;
			Matrix::printMatrix(matrices[1]);

			for (int i = 0; i < 2; i++)
			{
				delete matrices[i];
			}
			delete matrices;

			cout << "Enter any key to continue" << endl;
			_getch(); //reads a key without writing it and pressing enter
			system("cls");
			Matrix::printMenu(m1, m2);
		}
			break;
		case 4:
		{
			if (Matrix::CompareMatrices(m1, m2))
				cout << "These matrices are equal" << endl;
			else
				cout << "These matrices are not equal" << endl;

			cout << "Enter any key to continue" << endl;
			_getch(); //reads a key without writing it and pressing enter
			system("cls");
			Matrix::printMenu(m1, m2);
		}
			break;
		case 5:
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	}

	delete m1, m2;
}