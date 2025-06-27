#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <typename T>
class StackusingArray
{
	T top;
	int size;
	T* arr;

public:

	StackusingArray()
	{
		top = -1;
		cout << "\nEnter Size: ";
		cin >> size;
		arr = new T[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = '0';
		}

	}

	StackusingArray(int s)
	{
		top = -1;
		size = s;
		arr = new T[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = '0';
		}
	}

	void ReverseStack()
	{
		StackusingArray<T> temp(size);

		while (!isempty())
		{
			int t = Pop();
			temp.Push(t);
		}

		while (!temp.isempty())
		{
			int t = temp.Pop();
			Push(t);
		}

		cout << "\nAfter Reversing\n";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	void SortStack()
	{
		StackusingArray<int> sort(size);
		int i = 0;

		while (!isempty())
		{
			int temp = Pop();
			int top2 = top - 1;
			int tempprev=sort.arr[top];
			cout << "\nTEmp: " << temp;
			cout << "\nTemp Prev: " << tempprev << endl;

			while (temp > tempprev && !sort.isempty())
			{
				Push(sort.Pop());
			}
			sort.Push(temp);
			display();
			sort.display();
			i++;
		}














		/*while (i<7)
		{
			T temp = arr[top];
			cout << "\nTemp: " << temp;
			cout << "\nTop: " << sort.arr[top];

			if (sort.isempty())
			{
				cout << "\nemptyy\n";
				Pop();
				sort.Push(temp);
			}
			else
			if (temp > sort.arr[top-1])
			{
				cout << "\nEntering First\n";
				Pop();
				sort.Push(temp);
				cout << "\nTop: " << sort.arr[top];
				sort.display();
			}
			else if(temp<sort.arr[top])
			{
				cout << "\nEntering second\n";
				T temp2='0';
				while (temp2 < sort.arr[top] && !sort.isempty())
				{
					temp2 = sort.Pop();
					Push(temp2);
				}
				sort.Push(temp2);
			}
			i++;
		}*/







		/*while (!isempty())
		{
			T temp = arr[top];
			Pop();

			while (!sort.isempty() && sort.arr[top] > temp)
			{
				Push(sort.arr[top]);
				sort.Pop();
			}

			sort.Push(temp);
		}*/






		sort.display();
		


	}
	
	void Push(T e)
	{
		if (isfull())
		{
			cout << "\nStack is Full. Stack Overflow\n";
			return;
		}
		else
		{
			top++;
			arr[top] = e;
			
		}
	}

	T Pop()
	{
		if (isempty())
		{
			cout << "\nStack is empty. Stack Underflow\n";
			return -1;
		}
		else
		{
			T temp = arr[top];
			arr[top] =0;
			top--;
			return temp;
		}
	}

	void display()
	{
		cout << "\nDisplaying The Stack: \n";

		for (int i = size-1;i>=0; i--)
		{
			cout << arr[i] << endl;
		}

	}

	bool isempty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isfull()
	{
		if (top == size - 1)
			return true;
		else
			return false;
	}

	bool ParanthesisCheck()
	{
		int stringsize = 0;
		cout << "\n\nEnter String size: ";
		cin >> stringsize;
		cout << "\nPLease enter the string: ";
		char arr[20];
		for (int i = 0; i < stringsize; i++)
		{
			cin >> arr[i];
		}

		making 3 stacks for diff brackets
		StackusingArray<char> s1;
		StackusingArray<char> s2;
		StackusingArray<char> s3;

		
		int f1=0;
		int f2 = 0;
		int f3 = 0;
		char a='0';
		char b = '0';
		char c = '0';

		for (int i = 0; i < stringsize; i++)
		{
			if (arr[i] == '(')
			{
				a = arr[i];
				s1.Push(a);
			}
			else if (arr[i] == ')' )
			{
					T e = s1.Pop();
					checking first pushed bracket with other bracket
					if (e == a)
					{
						f1 = 1;
					}
			}

			if (arr[i] == '{')
			{
				b = arr[i];
				s2.Push(b);
			}
			else if (arr[i] == '}')
			{
					char d = s2.Pop();
					if (d == b)
					{
						f2 = 1;
					}
			}

			if (arr[i] == '[')
			{
				c = arr[i];
				s2.Push(c);
			}
			else if (arr[i] == ']')
			{

				char f = s2.Pop();
				if (c == f)
				{
					f3 = 1;
				}

			}
		}

		if (f2 == f1==f3)
			return true;
		else
			return false;
	}


	string infixtopostfix()
	{
		string infix;
		string postfix;
		cout << "\nPlease enter the string: ";
		infix = "2+3";
		/*cin >> infix;*/
		int infixsize = infix.size();
		cout << endl<<infixsize;

		for (int i = 0; i < infixsize; i++)
		{
			if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9')
				postfix = postfix+infix[i];
			else
				if (infix[i] == '(')
				{
					Push(infix[i]);
				}
				else
					if (infix[i] == ')')
					{
						
						while (top != '(' && !isempty())
						{
							char temp =Pop();
							postfix = postfix +temp;
						}
						postfix = postfix + infix[i];
					}
					else
						if (isOperator(infix[i]))
						{
							if (precedence(infix[i]) > precedence(top))
							{
								Push(infix[i]);
							}
							else
								if (precedence(infix[i]) < precedence(top))
								{
									while (!isempty() && precedence(infix[i]) <= precedence(top))
									{
										char temp = Pop();
										postfix = postfix + temp;
									}
									Push(infix[i]);
								}
						}
		}


		while (!isempty())
		{
			char temp = Pop();
			postfix = postfix + temp;
		}
		cout << "\nPostfix: " << postfix;

		return postfix;
	}

	void evaluatepostfix()
	{
		int result = 0;
		cout << "\nEvaluation of PostFix Called\n";
		string postfix = infixtopostfix();
		cout << "\n\n\nPostfix: " << postfix;

		for (int i = 0; i < postfix.length(); i++)
		{
			if (postfix[i] >= '0' && postfix[i] <= '9')
			{
				Push(postfix[i]);
			}
			else
				if (isOperator(postfix[i]))
				{

					int a = Pop();
					int b = Pop();

					cout << "\nA: " << a;
					cout << "\nB: " << b;

					if (postfix[i] == '+')
					{
						result = a + b;
					}
					else
						if (postfix[i] == '-')
						{
							result = a - b;
						}
						else
							if (postfix[i] == '*')
							{
								result = a * b;
							}
							else
								if (postfix[i] == '/')
								{
									result = a / b;
								}
					Push(result);
				}
		}

		result = Pop();
		cout <<"\nResult: "<< result;
	}

		bool isOperator(char c)
		{
			if (c == '+' || c == '-' || c == '*' || c == '/')
				return true;
			else
				return false;
		}



		int precedence(char c)
		{
			if (c == '*' || c == '/')
				return 2;
			else
				if (c == '+' || c == '-')
					return 1;
				else
					return -1;
		}

};

	int main()

	{
		StackusingArray<int> obj;
		obj.Push(2);
		obj.Push(8);
		obj.Push(1);
		obj.Push(9);
		obj.display();
		obj.SortStack();

		/*obj.ReverseStack();*/











		/*StackusingArray <char> obj2;*/

		/*int i = 0;
		while (i != -1)
		{
			cout << "\n1.) To Push Value\n";
			cout << "2.) To Pop Value\n";
			cout << "3.) Paranthesis Check\n";
			cout << "4.) Infix To PostFix\n";
			cout << "5.) Evaluate Expression\n";
			cout << "6.) Clear Screen\n";
			cout << "7.) Reverse Stack\n";
			cout << "8.) Display\n";
			cout << "9.) Exit\n";
			cout << "\nEnter Answer: ";
			cin >> i;


			if (i == 1)
			{
				char e;
				cout << "\nEnter Value to Push: ";
				cin >> e;
				obj.Push(e);
			}

			if (i == 2)
			{
				cout << "\nThe Popped Value is: " << obj.Pop();
			}

			if (i == 3)
			{
				cout << "\nAnswer Of Paranthesis Check is: "<<obj2.ParanthesisCheck();
			}

			if (i == 4)
			{
				obj2.ParanthesisCheck();
			}

			if (i == 5)
			{
				obj2.evaluatepostfix();
			}

			if (i == 6)
			{
				system("CLS");
			}

			if (i == 7)
			{
				obj.ReverseStack();
			}

			if (i == 9)
			{
				break;
			}

			if (i == 8)
			{
				obj.display();
			}

			if (i == 10)
			{
				obj.SortStack();
			}

		}*/

		system("pause");
		return 0;

	}