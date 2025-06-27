#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(char cards[], int x, int y)
{
	int temp = 0;
	temp = cards[x];
	cards[x] = cards[y];
	cards[y] = temp;
}

int main()
{
	/*char cards[3] = { 'J', 'Q', 'K' };*/
	char* cards = new char[3];
	cards[0] = 'K';
	cards[1] = 'Q';
	cards[2] = 'J';

	cout << "The original array was : ";

	for (int i = 0; i < 3; i++)
	{
		cout << cards[i] << " ";
	}

	int pen = 0;
	int bal = 100;
	int ans = 0, q = 0;
	int i = 0;

	while (i != -1 && bal != 0)
	{
		srand(time(0));
		int x = rand() % 3;
		int y = rand() % 3;
		cout << "\nThe random numbers generated are: " << x << " and " << y;
		swap(cards, x, y);
		cout << endl << endl;
		cout << "\nThe array after shuffling is: ";

		for (int i = 0; i < 3; i++)
		{
			cout << cards[i] << " ";
			if (cards[i] == 'Q')
				q = i;
		}

		cout << "\nPlease enter the number you want to check for the queen: ";
		cin >> ans;
		cout << "\n Please enter the penalty you are willing to pay: ";
		cin >> pen;


		if (ans == q)
		{
			bal = bal * 3;
			cout << "\nYou have won. Your reward is: " << bal;
			cout << endl << endl;

		}

		if (ans != q)
		{
			bal = bal - pen;
			cout << "Lol better luck next time XD ";
			cout << "\n Your current balance now is: " << bal;
			cout << endl << endl;
		}

		cout << "Do you want to try again? Press -1 to quit and 0 to play again \n";
		cin >> i;
	}

	delete[]cards;
	cards = nullptr;

	system("pause");
	return 0;
}