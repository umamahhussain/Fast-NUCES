#include <iostream>
using namespace std;

int *InputArr(int *p, int &size)
{
  
	cout << "Please enter the size of the array: ";
	cin >> size;
	p = new int[size];
	cout << "Please enter the elements of the array: \n";
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}

	return p;
}

int *IS(int* set1, int* set2, int s1, int s2, int& issize)
{
	int count = 0;
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (set1[i] == set2[j])
			{
				count++;
			}
		}
	}

	issize = count;

	int *is = new int[count];

	int k = 0;
	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			if (set1[i] == set2[j])
			{
				is[k] = set1[i];
				cout << is[k] << " ";
				k++;
			}
		}
	}

	cout << endl;
	return is;


}

int main()
{
	int	size1 = 0;
	int size2 = 0;
	int size3 = 0;
	int issize = 0;
	cout << "For set 1: \n";
	int *a = nullptr;
		a=InputArr(a, size1);
	cout << "For set 2: \n";
	int *b = nullptr;
	b=InputArr(b, size2);
	cout << "For set 3: \n";
	int *c = nullptr;
	c=InputArr(c, size3);
	

	

	cout << endl << endl;
	

	int*is1 = nullptr;
	is1=IS(a, b, size1, size2,issize);
	int *m = new int[issize];
	/*
	for (int i = 0; i < issize; i++)
	{
		m[i] = is1[i];
		cout << m[i];
	}*/
	

	
	int*is2 = nullptr;
	is1 = IS(a, c, size1, size3,issize);
	//int *m1 = new int[issize];

	//for (int i = 0; i < issize; i++)
	//{
	//	m1[i] = is2[i];
	//	cout << m1[i];
	//}

	
	int*is3 = nullptr;
	is3 = IS(b, c, size2, size3,issize);
	//int *m2 = new int[issize];
	//
	//for (int i = 0; i < issize; i++)
	//{
	//	m2[i] = is3[i];
	//	cout << m2[i];
	//}




	system("pause");
	return 0;
}