#include <iostream>
using namespace std;
class Bank 
{
public:

	int getBalance()
	{
		return 0;
	}

};


class Bank_A : public Bank
{
public:
	void getBalance()
	{
		cout<< "1000";
	}

};


class Bank_B : public Bank
{
public:
	void getBalance()
	{
		cout<<"1500";
	}

};



class Bank_C : public Bank
{
public:
	void getBalance()
	{
		cout << "2000";
	}

};








