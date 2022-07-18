#pragma once

#include <iostream>

template<typename T>
class Vector
{
private:
	T* cur;
	int size;
public:
	Vector(int size) : size(size)
	{
		cur = new T[size];
	}

	T* getVector() const
	{
		return cur;
	};
	int getSize() const 
	{
		return size;
	};

	void operator=(const Vector<T>& vector)
	{
		size = vector.size;
		cur = new T[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = vector.getVector()[i];
		}
	}
	Vector<T> operator-(int number)
	{
		Vector<T> temp(getSize());
		for (int i = 0; i < temp.getSize(); i++)
		{
			temp.cur[i] = cur[i];
		}

		for (int i = 0; i < temp.getSize(); i++)
		{
			temp.getVector()[i] -= number;
		}

		return temp;
	}
	Vector<T> operator-(const Vector<T>& vector)
	{
		Vector<T> temp(getSize() > vector.getSize() ? vector.getSize() : getSize());

		for (int i = 0; i < temp.getSize(); i++)
		{
			temp.cur[i] = cur[i] - vector.cur[i];
		}

		return temp;
	}
	Vector<T> operator--()
	{
		size--;
		T* arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = cur[i];
		}
		delete[] cur;
		cur = arr;

		return *this;
	}
	Vector<T> operator--(int)
	{
		size--;
		T* arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = cur[i];
		}
		delete[] cur;
		cur = arr;

		return *this;
	}

	// operator[]
	T& operator[](int i)
	{
		if (i > size) {
			std::cout << "Index out of bounds" << std::endl;
			return cur[0];
		}
		return cur[i];
	};

	friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vector)
	{
		for (int i = 0; i < vector.getSize(); i++)
		{
			os << vector.getVector()[i] << " ";
		}
		os << std::endl;

		return os;
	};
	friend std::istream& operator>>(std::istream& is, const Vector<T>& vector)
	{
		for (int i = 0; i < vector.getSize(); i++)
		{
			std::cout << "Enter " << i + 1 << " element : ";
			is >> vector.getVector()[i];
		}
		std::cout << std::endl;

		return is;
	};
};

