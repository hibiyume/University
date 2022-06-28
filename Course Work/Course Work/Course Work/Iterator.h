#pragma once

template <typename T>
class Iterator
{
private:
	T* current;
public:
	Iterator(T* first);

	T& operator+ (int n);
	T& operator- (int n);
	T& operator++(int);
	T& operator--(int);
	T& operator++();
	T& operator--();

	bool operator!=(const Iterator& it);
	bool operator==(const Iterator& it);
	T& operator*();
};
