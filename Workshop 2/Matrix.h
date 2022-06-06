#pragma once

class Matrix
{
private:
	int rows, columns;
	int** elements;

	static int objectCount;
public:
	Matrix();
	Matrix(const int rows, const int columns, int r_range1, int r_range2);
	Matrix(const int rows, const int columns, int** elements);
	Matrix(const Matrix& matrix);
	~Matrix();

	Matrix operator+(const Matrix& _m);
	Matrix operator-(const Matrix& _m);
	Matrix operator*(const Matrix& _m);
	void operator*=(const int& number);
	bool operator==(const Matrix& _m);

	int getRows();
	void setRows(int rows);
	int getColumns();
	void setColumns(int columns);
	int** getMatrix();
	void setMatrix(int** elements);
	static int getObjectCount();

	static void printMatrix(const Matrix& matrix);
	static Matrix SumMatrices(const Matrix& m1, const Matrix& m2);
	static Matrix SubstructMatrices(const Matrix& m1, const Matrix& m2);
	static Matrix MultiplyMatrices(const Matrix& m1, const Matrix& m2);
	static Matrix MultiplyMatrixByNumber(const Matrix& _m, int number);
	static bool CompareMatrices(const Matrix& m1, const Matrix& m2);
};