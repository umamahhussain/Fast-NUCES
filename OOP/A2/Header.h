#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
private:
	float* arr;
	int size;

public:

	Vector();
	Vector(Vector&);
	friend istream& operator >>(istream& in, Vector&);
	friend ostream& operator <<(ostream& out, Vector&);
	void operator * (const Vector&);
	Vector& operator^(Vector& obj1);
	void operator ==(Vector& obj1);
	void operator !=(Vector& obj1);
	Vector& operator = (Vector& obj1);
	float& operator[](int size);
	~Vector();
};

Vector::Vector()
{
	arr = nullptr;
	size = 0;
}

Vector::Vector(Vector& obj) {
	size = obj.size;
	for (int i = 0; i < obj.size; i++) {
		arr[i] = obj.arr[i];
	}
}
istream& operator >> (istream& in, Vector& obj) {

	cout << "Please enter the dimensions of the vector: ";
	in >> obj.size;
	obj.arr = new float[obj.size];
	cout << "\nPlease enter the components of the vector: \n";

	for (int i = 0; i < obj.size; i++)
	{
		in >> obj.arr[i];
	}
	cout << endl << endl;
	return in;
}

ostream& operator << (ostream& out, Vector& obj)
{
	out << "\n< ";
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.arr[i] << " ";
	}
	out << " >\n\n";
	return out;
}

void Vector::operator * (const Vector& obj1)
{
	float sum = 0;

	for (int i = 0; i < obj1.size; i++)
	{
		sum = sum + obj1.arr[i] * arr[i];
	}

	cout << "dot product: " << sum;
}

Vector& Vector:: operator ^ (Vector& obj1)
{
	float sum = 0;

	for (int i = 0; i < obj1.size; i++)
	{
		sum = sum + (obj1.arr[i] * obj1.arr[i]);
	}

	sum = sqrt(sum);
	cout << "Unit Vector: ";
	cout << obj1.arr[0] << "/" << sum;
	for (int i = 1; i < obj1.size; i++) {
		cout << " + " << obj1.arr[i] << "/" << sum;
	}
	cout << endl;
	return *this;
}

void Vector:: operator ==(Vector& obj1)
{
	cout << "\nTo Check if two vectors are equal:\n";
	int flag = 0;
	for (int i = 0; i < obj1.size; i++)
	{
		if (obj1.arr[i] == arr[i])
		{
			;
		}
		else
			flag = 1;
	}

	if (flag == 0)
		cout << "\nTrue";
	else
		cout << "\nFalse\n";
}

void Vector:: operator !=(Vector& obj1)
{
	cout << "\nTo Check if two vectors are unequal:\n";
	int flag = 0;
	for (int i = 0; i < obj1.size; i++)
	{
		if (obj1.arr[i] == arr[i])
		{
			;
		}
		else
			flag = 1;
	}

	if (flag == 0)
		cout << "False";
	else
		cout << "\nTrue :)\n";
}

Vector& Vector::operator =(Vector& obj1)
{

	size = obj1.size;
	for (int i = 0; i < size; i++) {
		arr[i] = obj1.arr[i];
	}
	return *this;
}

float& Vector::operator[](int n)
{
	if (n > size)
		cout << "Index out of bounds";
	else 
	{
		return arr[n];
	}
}
Vector::~Vector()
{
	delete[]arr;
	size = 0;
}