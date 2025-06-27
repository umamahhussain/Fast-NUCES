#include <iostream>
#include "Header.h";
using namespace std;
int main()
{
	int n = 0;

	cout << "Welcome to the library\n";
	cout << "Please tell the number of books: ";
	cin >> n;

	Books *p = new Books[n];

	for (int i = 0; i < n; i++)
	{
		p[i].settitle();
		p[i].setauthor();
		p[i].setnum();
		p[i].setbookid();
		p[i].gettitle();
		p[i].getauthor();
		p[i].getid();
		p[i].getnum();
	}

	cout << "ALL THE BOOKS AVAILABLE ARE: \n\n";
	for (int i = 0; i < n; i++)
	{
		p[i].gettitle();
		p[i].getauthor();
		p[i].getid();
		p[i].getnum();
	}

	Student obj;
	obj.setbooknum();
	obj.setbooknum();
	obj.setlname();
	obj.setrollnum();







	system("pause");
	return 0;
}