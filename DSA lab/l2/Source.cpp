#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	int dnum;
	cout << "\nEnter the dimensional structure that you require: ";
	cin >> dnum;

	ndarr <int> obj(dnum);
	cin >> obj;
	cout << obj;
	int* p=nullptr;
	obj.Insert(22, p);
	cout << "\nAfter Insertion: \n";
	cout << obj;
	cout << "\nAfter Expansion: \n";
	obj.Extend();
	cout << "\nAfter Shrinking: \n";
	obj.shrink();

	if (dnum == 1)
	{
		cout << "\nEnter index that you want to retrieve : ";
		int s;
		cin >> s;
		cout << obj[s];
	}
	else
		if (dnum == 2)
		{
			cout << "\nEnter indexes that you want to retrieve : ";
			int i,j=0;
			cin >> i;
			cin >> j;
			cout << obj[i,j];
		}
		else
			if (dnum == 3)
			{
				cout << "\nEnter indexes that you want to retrieve : ";
				int i, j ,k= 0;
				cin >> i;
				cin >> j;
				cin >> k;
				cout << obj[i, j,k];
			}
}