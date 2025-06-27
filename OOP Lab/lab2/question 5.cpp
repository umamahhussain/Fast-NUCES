#include <iostream>
using namespace std;

int* Input(int& size)
{
	cout << "Please enter the size of the array: ";
	cin >> size;
	cout << "\nPlease enter the elements of the array:\n";
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	return &*arr;
}

void copyArray(int* arr, int*& arr1, int size)
{
	arr1 = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
	}

	cout << "The copied array is:\n\n";

	for (int i = 0; i < size; i++)
	{
		cout << arr1[i];
	}

	cout << endl << endl;
}

int* findmin(int* nptr, int size)
{
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (nptr[index] > nptr[i])
		{
			index = i;
		}
	}

	return &*nptr + index;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int* arr, int size)
{
	int* nptr;
	for (int i = 0; i < size; i++)
	{
		nptr = findmin(arr + i, size - i);
		swap(nptr, arr + i);
	}

	cout << "The sorted array is as follows: \n\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}


void reduceArray(int* arr, int* arr1, int size)
{
	sort(arr1, size);
	
	cout << "\n\nThe sorted array after processing is\n\n";

	for (int i = 0; i < size; i++)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (arr1[i] == arr1[j])
				break;
		}
		if (i == j)
			cout << arr1[i] << " ";
	}

}





int main()
{
	int size;
	int* arr1;
	int* arr = Input(size);
	copyArray(arr, arr1, size);
	reduceArray(arr, arr1, size);

	return 0;
}