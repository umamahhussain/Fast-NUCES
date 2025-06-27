#include <iostream>
using namespace std;

int count(int num,int rev, int start, int &counter)
{
	if (start <= 0)
		return counter;


	if (num <= 0)
	{
		start--;
		num = start;
	}
	
	if(num>0)
	{
	  int rem = num % 10;
	  if (rem == 1 || num==1)
	  {
		  counter++;
	  }
	  rev = rev * 10 + rem;
	  num = num / 10;
      count(num, rev,start,counter);
	}

}

int main()
{

	int val = 0;
	cout << "\nEnter the value you want to find: ";
	cin >> val;
	int counter = 0;

	count(val, 0, val, counter);
	cout <<"\nThe total occurences of 1 are: "<< counter;

	cout << endl << endl;
	system("pause");
	return 0;



}