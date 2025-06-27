#include <iostream>
using namespace std;

class student{
	int *smarks = new int[5];
public:
	student()
	{
		cout << "Default Constructor Called" << endl;
	}
	void copy(student & s)
	{
		smarks = s.smarks;
	}
	void cpy(student & obj2)
	{
		for (int i = 0; i < 5; i++)
		{
			smarks[i] = obj2.smarks[i];
		}
	}
	void set_marks(int marks, int idx)
	{
		if (idx >= 0 && idx < 5)
		{
			smarks[idx] = marks;
		}
		else
		{
			cout << "invalid index" << endl;
		}
	}
	void output()
	{
		cout << "Your marks are:" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << smarks[i] << endl;
		}
	}
	student(student & obj)
	{
		for (int i = 0; i < 5; i++)
		{
			smarks[i] = obj.smarks[i];
		}
	}

	void modify(int idx, int marks)
	{
		cout << "Your marks after modification are:" << endl;
		smarks[idx] = marks;
	}

	~student()
	{
		delete[] smarks;
		cout << "Destructor" << endl;
	}

};
int main()
{
	student s1;
	int m; 
	cout << "Please enter your marks:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> m;
		s1.set_marks(m, i);
	}
	s1.output();
	student s2;
	s2.cpy(s1);
	s1.modify(3, 20);
	//s1.~student();
	s1.output();
	s2.output();

	system("pause");
	return 0;
}