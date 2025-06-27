#include <iostream>
using namespace std;

bool palindrome(char* arr, int high, int low, int c)
{
	cout << "\nLOW: " << low;
	cout << "\nHIGH: " << high;
	if (low > high)
	{
		if (c == 1)
		{
			cout << "\nString is a palindrome\n";
			return true;
		}
		else
		{
			cout << "\nString is not a palindrome\n";
			return false;
		}
	}
	else
	{
		if (low <= high)
		{
			if (arr[low] == arr[high])
			{
				cout << "\nenter";
				cout << "\nlow:" << arr[low];
				cout << "\nhigh: " << arr[high];
				low++;
				high--;
				c = 1;
				palindrome(arr, high, low, c);
			}
			else
			{
				cout << "\nString is not a palindrome\n";
				return false;
				c = -1;
			}
		}

	}
}


int main()
{
	int s = 0;
	cout << "\nEnter Size: ";
	cin >> s;
	char* arr = NULL;
	arr = new char[s];


	for (int i = 0; i < s; i++)
		cin >> arr[i];




	palindrome(arr, s - 1, 0, 0);

}