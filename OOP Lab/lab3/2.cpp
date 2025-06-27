#include <iostream>
using namespace std;

int* Fibonacci_series(int num)
{
	int num1 = 1;
	int num2 = 1;
	int series[10] = { 0 };
	series[0] = num1;
	series[1] = num2;
	for (int i = 2; i < num; i++)
	{
		int num3 = num1 + num2;
		series[i] = num3;
		num1 = num2;
		num2 = num3;
	}

	for (int i = 0; i < num; i++)
		cout << series[i] << " ";

	cout << endl;
	return &series[num - 1];
}

int main()
{
	int num = 0;
	cout << "Please enter the num for the series: ";
	cin >> num;
	int* x = Fibonacci_series(num);
	cout << endl;
	cout << x<<endl<<endl;


	system("pause");
	return 0;
}