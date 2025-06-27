#include <iostream>
using namespace std;

int** AllocateMem(int &r, int &c)
{
	cout << "Please enter the number of rows: ";
	cin >> r;
	cout << "\nPlease enter the number of columns: ";
	cin >> c;
	int** m = nullptr;
	m = new int*[r];

	for (int i = 0; i < r; i++)
	{
		m[i] = new int[c];
	}

	return m;

}

void InputMatrix(int** m1, int r, int c)
{
	cout << "\nPlease enter the elements: \n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m1[i][j];
		}
	}
}

void OutputMatrix(int** m1, int r, int c)
{
	cout << endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout<< m1[i][j]<<'\t';
		}
		cout << endl;
	}
}

void Rotate(int** m1, int r, int c)
{
	int oop = m1[c - 1][0];

	//first column 
	for (int i = r - 1, j = 0; i >= 1; i--)
	{
		m1[i][j] = m1[i - 1][j];
	}

	//first row
	for (int i = 0, j = 0; j <= c - 2; j++)
	{
		m1[i][j] = m1[i][j + 1];
	}

	//last column
	for (int i = 0, j = c - 1; i <= r - 2; i++)
	{
		m1[i][j] = m1[i + 1][j];
	}

	//last row
	for (int i = r - 1, j = c - 1; j >= 1; j--)
	{
		m1[i][j] = m1[i][j - 1];
	}

	m1[c-1][1] = oop;


	cout << endl << endl;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m1[i][j] << '\t';
		}
		cout << endl;
	}





}



int main()
{
	int** m1 = nullptr;
	int r, c;
	m1 = AllocateMem(r, c);
	InputMatrix(m1, r, c);
	OutputMatrix(m1, r, c);
	Rotate(m1, r, c);


	return 0;
 }