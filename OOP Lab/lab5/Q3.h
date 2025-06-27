#include <iostream>
using namespace std;

class Rectangle
{
public:
	int length;
	int width;

	Rectangle();
	Rectangle(int );
	Rectangle(int , int );

};

Rectangle::Rectangle()
{
	cout << "Default constructor called: "<<endl;
	length = 0;
	width = 0;
}

Rectangle::Rectangle(int a)
{
	length = a;
	width = a;

	int area = length*width;
	cout << "The calculated area is: " << area << endl;
}

Rectangle::Rectangle(int a, int b)
{
	length = a;
	width = b;
	int area = length * width;
	cout << "The calculated area is: " << area << endl;
}