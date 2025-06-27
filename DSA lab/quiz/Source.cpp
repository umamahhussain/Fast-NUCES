#include <iostream>
using namespace std;

void tellrows(int a)
{
	int start = 1;
	int end = 1;
	int mid = 0;
	int f = 0;

		if (a == 1)
		{
			cout << "[" << start << "]";
			
		}
		else
		if (a == 2)
		{
			cout << "[" << start<<","<<end << "]";
			
		}
		else
		if (a > 2)
		{
			for (int i = 0; i < a; i++)
			{
				
				if (i < 2 && f==0)
				{
					cout << "[" << start << "],";
					cout << "[" << start << ","<<end << "]";
					f = 1;
				}
				else
				if (i>2)
				{
					for (int i = 3; i < a; i++)
					{
						mid = start + end;
						cout << "[" << start;
						for (int j = 0; j < i; j++)
						{
							cout << ", " << mid<<", ";
						}
						cout << end << " ]";
					}
				}


			}
		}
	
}







int main()
{

	int a = 3;
	tellrows(a);



	system("pause");
	return 0;
}