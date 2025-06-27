#include <iostream>
using namespace std;

int* Inputset(int& size)
{

	cout << "please enter size of the array: ";
	cin >> size;
	int* set = new int[size];
	cout << endl << "Please enter the elements of the array \n";
	for (int i = 0; i < size; i++)
		cin >> set[i];

	return &*set;
}

void Outputset(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
		cout << ptr[i] << " ";
}

bool isElement(int* set, int x, int s)
{

	for (int i = 0; i < s; i++)
	{
		if (x == set[i])
			return true;
	}
	return false;
}

int* Compress(int* set, int& size)
{
	int count = 1, flag = 0;

	for (int i = 1; i < size; i++)
	{
		flag = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (set[i] == set[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			count++;
		}
	}

	int* setc = new int[count];

	for (int i = 0, k = 0; i < size && k < count; i++)
	{
		flag = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (set[i] == set[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			setc[k] = set[i];
			k++;
		}
	}
	size = count;
	return &*setc;

}

int* Intersection(int s1, int s2, int* set1, int* set2, int& s3)
{
	int count = 0;
	int* set1c = Compress(set1, s1);
	int* set2c = Compress(set2, s2);

	//cout << "Compressed set 1 is: \n";

	/*for (int i = 0; i < s1; i++)
	{
		cout << set1c[i] << " ";
	}

	cout << endl << endl;

	cout << "Compressed set 2 is: \n";
	for (int i = 0; i < s2; i++)
	{
		cout << set2c[i] << " ";
	}*/

	if (s1 <= s2)
	{
		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				if (set1c[i] == set2c[j])
				{
					count++;
				}
			}
		}

		int* set3 = new int[count];
		s3 = count;

		for (int i = 0, k = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				if (set1c[i] == set2c[j])
				{
					set3[k] = set1c[i];
					k++;
				}

			}
		}
		for (int i = 0; i < s3; i++)
		{
			cout << set3[i] << " ";
		}
		return &*set3;
	}

	if (s2 < s1)
	{
		for (int i = 0; i < s2; i++)
		{
			for (int j = 0; j < s1; j++)
			{
				if (set1c[j] == set2c[i])
				{
					count++;
				}
			}
		}

		int* set3 = new int[count];
		s3 = count;

		for (int i = 0, k = 0; i < s2; i++)
		{
			for (int j = 0; j < s1; j++)
			{
				if (set1c[j] == set2c[i])
				{
					set3[k] = set2c[i];
					k++;
				}

			}
		}

		for (int i = 0; i < s3; i++)
		{
			cout << set3[i] << " ";
		}
		return &*set3;
	}


}

int* Union(int* set1, int* set2, int s1, int s2, int&s5)
{

	int s3 = s1 + s2;
	int* set3 = new int[s3];

	for (int i = 0; i < s1; i++)
		set3[i] = set1[i];

	for (int j = s1; j < s3; j++)
	{
		set3[j] = set2[j - s1];
	}
	
	int* set3c = Compress(set3, s3);
	s5 = s3;
	

	return *&set3c;
}



int* differenceArray(int* arr1, int& s1, int* arr2, int& s2, int& s4) {
	int choice;
	bool flag;
	cout << "1 for A-B / 2 for B-A: ";
	cin >> choice;
	if (choice == 1) 
	{
		int size = 0;
		for (int i = 0; i < s1; i++) 
		{
			flag = false;
			for (int j = 0; j < s2; j++) 
			{
				if (arr1[i] == arr2[j])
					flag = true;
			}
			if (!flag)
				size++;
		}

		int* diffArray = new int[size];

		for (int i = 0, k = 0; i < s1; i++) 
		{
			flag = false;
			for (int j = 0; j < s2; j++) 
			{
				if (arr1[i] == arr2[j])
					flag = true;
			}
			if (!flag) 
			{
				diffArray[k]  = arr1[i];
				k++;
			}
		}
		s4 = size;
		return *&diffArray;
	}
	if (choice == 2) 
	{
		int size = 0;
		for (int i = 0; i < s2; i++) 
		{
			flag = false;
			for (int j = 0; j < s1; j++)
			{
				if (arr2[i] == arr1[j])
					flag = true;
			}
			if (!flag)
				size++;
		}
		int* diffArray = new int[size];
		for (int i = 0, k = 0; i < s2; i++) 
		{
			flag = false;
			for (int j = 0; j < s1; j++)
			{
				if (arr2[i]  == arr1[j])
					flag = true;
			}
			if (!flag) 
			{
				diffArray[k] = arr2[i];
				k++;
			}
		}
		s4 = size;
		return *&diffArray;
	}
}


void Comp(int* set1, int* set2, int s1, int s2, int s3)
{

	int* uni = Union(set1, set2, s1, s2, s3);
	cout << "\n\n\nThe comp of the set is: ";
	bool flag;
	int size = 0;

	for (int i = 0; i < s3; i++)
	{
		flag = false;
		for (int j = 0; j < s1; j++)
		{
			if (uni[i] == set1[j])
				flag = true;
		}
		if (!flag)
			size++;
	}

	int* comparr = new int[size];
	int s4 = size;

	for (int i = 0, k = 0; i < s3; i++)
	{
		flag = false;
		for (int j = 0; j < s1; j++)
		{
			if (uni[i] == set1[j])
				flag = true;
		}
		if (!flag)
		{
			comparr[k] = uni[i];
			k++;
		}
	}
	
	for (int i = 0; i < s4; i++)
	{
		cout << comparr[i] << " ";
	}

}

int main()
{
	int* set1, * set2;
	int s1, s2;
	int s3 = 0,s4=0,s5=0;
	cout << "For set 1: \n";
	set1 = Inputset(s1);
	cout << "For set 2: \n";
	set2 = Inputset(s2);

	cout << "\nSet 1: \n";
	Outputset(set1, s1);
	cout << "\nSet 2: \n";
	Outputset(set2, s2);

	int ans = 0;
	cout << endl << endl;
	cout << "Do you want to find a specific element from a set? Press 1 for yes and press 0 for no: ";
	cin >> ans;
	
	
		if (ans == 1)
		{
			int s = 0,f=0;
			int* set = Inputset(s);
			int x = 0;
			cout << "Please enter the variable you want to search in the set: ";
			cin >> x;
			f= isElement(set, x, s);
			if (f == 0)
				cout << "\nThe element is not found\n";
			else
				cout << "\nThe element is found\n";
		}

		while (ans != -1)

		{
			cout << "\nEnter -1 to exit ";
			cout << "\nPress 2 to find the intersection of the set: ";
			cout << "\nPress 3 to find the union of the set: ";
			cout << "\nPress 4 to find the difference of the sets: ";
			cout << "\nPress 5 to find the complement of the sets: ";
			cout << "\nYour answer: ";
			cin >> ans;

			if (ans == 2)
			{
				cout << "\nThe Intersection of the sets is: \n";
				Intersection(s1, s2, set1, set2, s3);
			}

			if (ans == 3)
			{
				cout << endl << endl;
				cout << "The Union of the sets is: ";
				int *unii=Union(set1, set2, s1, s2,s3);
				for (int k = 0; k < s3; k++)
				{
					cout << unii[k] << " ";
				}
			}
			
			if (ans == 4)
			{
				cout << "\nThe difference of the sets is: ";
				int *diff=differenceArray(set1, s1, set2, s2, s4);
				for (int i = 0; i < s4; i++)
				{
					cout << diff[i] << " ";
				}
			}

			if (ans == 5)
			{
				Comp(set1, set2, s1, s2, s3);
			}
		}
			return 0;
		
}