#include <iostream>
#include <vector>

using namespace std;

int SIZE = 5;
int RANGE = 10;

void printArray(const vector<double>& arr, int size);
double getMinValue(const vector<double>& arr);
double getMaxValue(const vector<double>& arr);
void sortArrayInAscending(vector<double>& arr);
void insertElement(vector<double>& arr, int value, int index);
void deleteElement(vector<double>& arr, int index);

//iterator functions
double countPositiveElements(const vector<double>& arr);
double sumElementsAfterZero(const vector<double>& arr);

int main()
{
	//srand(time(NULL));

    vector<double> arr;
	
	for (int i = 0; i < SIZE; i++)
	{
		arr.push_back(rand() % (2 * RANGE + 1) - RANGE);
	}

	printArray(arr, SIZE);
	cout << "Max Value : " << getMaxValue(arr) << endl;
	cout << "Min Value : " << getMinValue(arr) << endl;

	cout << endl;
	sortArrayInAscending(arr);
	cout << "Sorted array in ascending order :" << endl;
	printArray(arr, SIZE);

	cout << endl;
	insertElement(arr, 25, 3);
	cout << "Inserting element 25 on the 4th position of the array. New array :" << endl;
	SIZE++;
	printArray(arr, SIZE);

	cout << endl;
	deleteElement(arr, 3);
	cout << "Deleting element 25 from the 4th position of the array. New array :" << endl;
	SIZE--;
	printArray(arr, SIZE);

	cout << endl;
	cout << "Iterator functions :" << endl;
	cout << "Number of positive elements in the array : " << countPositiveElements(arr) << endl;
	cout << "Sum of elements located after element with 0 value (Or sum of elements after minimum element if there no elements with 0 value) : " << sumElementsAfterZero(arr);
}

void printArray(const vector<double>& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double getMinValue(const vector<double>& arr)
{
	double min = RANGE + 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
double getMaxValue(const vector<double>& arr)
{
	double max = RANGE - 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void sortArrayInAscending(vector<double>& arr)
{
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void insertElement(vector<double>& arr, int value, int index)
{
	vector<double> temp;

	for (int i = 0; i < index; i++)
	{
		temp.push_back(arr[i]);
	}
	temp.push_back(value);
	for (int i = index + 1; i < SIZE + 1; i++)
	{
		temp.push_back(arr[i - 1]);
	}

	arr = temp;
}
void deleteElement(vector<double>& arr, int index)
{
	vector<double> temp;

	for (int i = 0; i < index; i++)
	{
		temp.push_back(arr[i]);
	}
	for (int i = index + 1; i < SIZE; i++)
	{
		temp.push_back(arr[i]);
	}

	arr = temp;
}

//iterator functions
double countPositiveElements(const vector<double>& arr)
{
	int number = 0;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		if (*it >= 0)
			number++;
	}

	return number;
}
double sumElementsAfterZero(const vector<double>& arr)
{
	double sum = 0;

	bool hasZero = false;
	int indexZero;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			hasZero = true;
			indexZero = i;
			break;
		}
	}
	
	if (hasZero)
	{
		for (int i = indexZero; i < SIZE; i++)
		{
			sum += arr[i];
		}
	}
	else
	{
		double min = getMinValue(arr);
		int indexMin;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i] == min)
			{
				indexMin = i;
				break;
			}
		}
		for (int i = indexMin; i < SIZE; i++)
		{
			sum += arr[i];
		}
		sum -= min;
	}

	return sum;
}