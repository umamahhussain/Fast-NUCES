#include <iostream>
#include <cstring>
using namespace std;

void Input(char*& arr, int& size)
{
	cout << "Please enter the size of the array: ";
	cin >> size;
	arr = new char[size];
	int count = 0;

	cout << "Please enter the elements of the array: \n";

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
		count++;
		if (arr[i] == 'q')
			break;

		if (count == size)
			size = size * 2;
	}

	size = count;

}




void Output(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}


void reverse(char* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{

		int temp = arr[i];
		arr[i] = arr[(size - 1) - i];
		arr[(size - 1) - i] = temp;

	}

	cout << "After processing the array becomes: ";
	Output(arr, size);

}


int main()
{

	char* arr;
	int size = 0;
	Input(arr, size);
	reverse(arr, size);

	system("pause");
	return 0;
}
