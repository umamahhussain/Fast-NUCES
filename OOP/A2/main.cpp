#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	Vector v1;
	Vector v2;
	Vector v3;
	cin >> v1;
	cout << v1;
	cin >> v2;
	cout << v2;
	cin >> v3;
	cout << v3;
	v1* v2;
	v1 == v2;
	v1 != v2;
	v1^ v2^ v3;
	v1 = v2 = v3;
	cout << v1;
	cout << v2 << v3;
	int index;
	cout << "Enter Index: ";
	cin >> index;
	cout << v1[index] << endl;
	cin >> v1[index];
	cout << v1;
	return 0;
}