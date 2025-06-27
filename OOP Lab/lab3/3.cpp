#include <iostream>
using namespace std;

char* encrypt(char mystr[], int x)
{
	for (int i = 0; i < x; i++)
	{
		mystr[i] = mystr[i] + x;
	}

	for (int i = 0; i < x; i++)
	{
		cout << mystr[i];
	}
	return &*mystr;

}

char* decrypt(char mystr[], int x)
{

	for (int i = 0; i < x; i++)
	{
		mystr[i] = mystr[i] - x;
	}

	for (int i = 0; i < x; i++)
	{
		cout << mystr[i];
	}

	return &*mystr;
}


int main()
{
	char arr[100] = "0";
	cout << "Please enter the message: ";
	cin.getline(arr, 100);
	cout << endl << endl;
	int x = strlen(arr);
	cout << "The length of the string is " << x;
	cout << endl << endl;
	cout << "The encrypted message is as follows: \n";
	char *y=encrypt(arr, x);
	cout << endl << endl;
	cout << "The decrypted message is as follows: \n";
	decrypt(y, x);
	cout << endl << endl;

	system("pause");
	return 0;
}
