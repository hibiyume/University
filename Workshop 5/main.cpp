#include <iostream>

#include "Vector.h"

using namespace std;

int main()
{
	auto vec1 = Vector<int>(3);
	auto vec2 = Vector<int>(4);

	cout << "   Vector 1 : " << endl;
	cin >> vec1;
	cout << "   Vector 2 : " << endl;
	cin >> vec2;

	cout << "Vector 1 : " << vec1 << endl;
	cout << "Vector 2 : " << vec2 << endl;

	cout << "Result of {Vector1 - 2} : ";
	auto temp = vec1 - 2;
	cout << temp;

	cout << "Result of {Vector1 - Vector2} : ";
	temp = vec1 - vec2;
	cout << temp;

	cout << "Result of using decrement operator-- (deletes last element from vector) : " << endl;
	cout << "Vector 2 : ";
	vec2--;
	cout << vec2;

	delete[] temp.getVector();
	delete[] vec1.getVector();
	delete[] vec2.getVector();
}