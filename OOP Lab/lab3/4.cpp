#include <iostream>
using namespace std;

char** AllocateMemory(int& r, int& c)
{

	cout << "Please enter the number of rows: ";
	cin >> r;
	cout << "\nPlease enter the number of columns: ";
	cin >> c;
	char** m;
	m = new char* [r];

	for (int i = 0; i < r; i++)
	{
		m[i] = new char[c];
	}

	return m;
}

void Inputmatrix(char** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];
		}
	}
}

void Outputmatrix(char** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "  ";
		}
		cout << endl;
	}
}

void num(char** m, int r, int c)
{
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] >= '0' && m[i][j] <= '9')
			{
				count++;
			}
		}
	}
		char* num = new char[count];

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (m[i][j] >= '0' && m[i][j] <= '9')
				{
					num[count] = m[i][j];
					cout << num[count] << " ";
					
				}
			}

		}
	
}

void alpha(char** m, int r, int c)
{
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] >= 'a' && m[i][j] <= 'z' || m[i][j] >= 'A' && m[i][j] <= 'Z')
			{
				count++;
			}
		}
	}

	char* alpha = new char[count];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c ; j++)
		{
			if (m[i][j] >= 'a' && m[i][j] <= 'z' || m[i][j] >= 'A' && m[i][j] <= 'Z')
			{
				alpha[count] = m[i][j];
				cout << alpha[count] << " ";
			}
		}
	}
}

void specchar(char** m, int r, int c)
{
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] >= 'a' && m[i][j] <= 'z' || m[i][j] >= 'A' && m[i][j] <= 'Z' || m[i][j] >= '0' && m[i][j] <= '9')
			{
				continue;
			}
			else
				count++;
		}
	}

	char* spchar = new char[count];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] >= 'a' && m[i][j] <= 'z' || m[i][j] >= 'A' && m[i][j] <= 'Z' || m[i][j] >= '0' && m[i][j] <= '9')
			{
				continue;
			}
			else
				spchar[count] = m[i][j];
			cout << spchar[count] << " ";
		}
	}

}

			
int main()	
{

  char** m1;
  int rows, columns;
  m1 = AllocateMemory(rows, columns);
  Inputmatrix(m1, rows, columns);
  cout << endl << endl;
  Outputmatrix(m1, rows, columns);
  cout << endl << endl;
  cout << "The array for numbers is: ";
  num(m1, rows, columns);
  cout << endl << endl;
  cout << "The array for alphabets is: ";
  alpha(m1, rows, columns);
  cout << endl << endl;
  cout << "The array for special characters is: ";
  specchar(m1 , rows, columns);
  cout << endl;
	system("pause");
	return 0;
}