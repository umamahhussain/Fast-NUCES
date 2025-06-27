#include<iostream>
using namespace std;
struct node
{
	node* next;
	int key;
	int value;
	int present;
	node()
	{
		next = NULL;
		key = value = 0;
		present = 0;
	}
	node(int k, int v)
	{
		key = k;
		value = v;
		next = NULL;
		present = 0;
	}
};
class HashTable
{
private:
	int size; // Size will always be odd
	node* arr;
	int c_method;
	bool re_hash;
public:
	//loading f is the no of elements divided by the size of
	HashTable(bool f, int c)
	{
		size = 13;
		arr = new node[size];
		c_method = c;
		re_hash = f;
	}
	float loading_factor()
	{
		float c = 1;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].value != 0)
			{
				c++;
			}
		}
		c = c / size;
		return c;
	}
	void call_rehashing()
	{
		node* store_arr = new node[size * 2];
		size *= 2;
		for (int i = 0; i < size / 2; i++)
		{
			if (arr[i].present == 1)
			{
				insertion(arr[i].key, arr[i].value, store_arr);
			}
		}
		arr = store_arr;

	}
	int hash_func(int k)
	{
		return k % size;
	}
	int hash_func_2(int k)
	{
		return (1 + k % (size - 2));
	}
	int call_probing(int k, int ind)  //we will add probe into the home index and then we will check if there is data or not
	{
		if (c_method == 1)
		{
			return ind;
		}
		else if (c_method == 2)// prob with the step 
		{
			return (ind * 3);
		}
		else if (c_method == 3)
		{

		}
		else if (c_method == 4)//double hashing 
		{
			return (ind * hash_func_2(k));
		}

	}
	void insertion(int key, int val, node* n)
	{

		int h_index = hash_func(key);

		if (c_method == 1)
		{
			//LINEAR PROBING 
			if (n[h_index].value == 0)
			{
				n[h_index].value = val;
				n[h_index].present = 1;
				n[h_index].key = key;

			}
			else
			{
				h_index = call_probing(key, h_index);
				int p = h_index;
				while (n[h_index].present != 0)
				{
					h_index = call_probing(key, p);
					p++;
				}
				n[h_index].key = key;
				n[h_index].value = val;
				n[h_index].present = 1;
			}
		}
		else if (c_method == 2)
		{
			if (n[h_index].value == 0)
			{
				n[h_index].value = val;
				n[h_index].key = key;
				n[h_index].present = 1;
			}
			else
			{
				int j = 0;
				int v = 0;
				v = call_probing(key, v);
				while (n[(h_index + v) % size].present != 0)
				{
					v++;
					j++;
					v = call_probing(key, j);
				}
				n[(h_index + v) % size].value = val;
				n[(h_index + v) % size].key = key;
				n[(h_index + v) % size].present = 1;

			}
		}
		else if (c_method == 4)
		{
			if (n[h_index].value == 0)
			{
				n[h_index].value = val;
				n[h_index].key = key;
				n[h_index].present = 1;
			}
			else
			{
				int time = 0;
				int h_2_save = hash_func_2(key);
				h_2_save = time * h_2_save;
				while (n[(h_index + h_2_save) % size].value != 0)
				{
					time++;
					h_2_save = hash_func_2(key);
					h_2_save = time * h_2_save;
				}
				n[(h_index + h_2_save) % size].value = val;
				n[(h_index + h_2_save) % size].key = key;
				n[(h_index + h_2_save) % size].present = 1;
			}
		}
	}
	void insertion(int key, int val)
	{
		if (re_hash)
		{
			float save_lf = 0;
			save_lf = loading_factor();
			if (save_lf > 0.5)
			{
				call_rehashing();
			}
		}
		int h_index = hash_func(key);

		if (c_method == 1)
		{
			//LINEAR PROBING 
			if (arr[h_index].value == 0)
			{
				arr[h_index].value = val;
				arr[h_index].key = key;
				arr[h_index].present = 1;
			}
			else
			{
				h_index = call_probing(key, h_index);
				int p = h_index;
				while (arr[h_index].present != 0)
				{
					h_index = call_probing(key, p);
					p++;
				}
				arr[h_index].value = val;
				arr[h_index].key = key;
				arr[h_index].present = 1;
			}
		}
		else if (c_method == 2)//probing with steps 
		{
			if (arr[h_index].value == 0)
			{
				arr[h_index].value = val;
				arr[h_index].key = key;
				arr[h_index].present = 1;
			}
			else
			{
				int j = 0;
				int v = 0;
				v = call_probing(key, v);
				while (arr[(h_index + v) % size].present != 0)
				{
					v++;
					j++;
					v = call_probing(key, j);
				}

				arr[(h_index + v) % size].value = val;
				arr[(h_index + v) % size].key = key;
				arr[(h_index + v) % size].present = 1;

			}
		}
		else if (c_method == 3)
		{

		}
		else if (c_method == 4)//double hashing
		{
			if (arr[h_index].value == 0)
			{
				arr[h_index].value = val;
				arr[h_index].key = key;
				arr[h_index].present = 1;
			}
			else
			{
				int time = 0;
				int h_2_save = hash_func_2(key);
				h_2_save = time * h_2_save;
				while (arr[(h_index + h_2_save) % size].present != 0)
				{
					time++;
					h_2_save = hash_func_2(key);
					h_2_save = time * h_2_save;
				}
				arr[(h_index + h_2_save) % size].value = val;
				arr[(h_index + h_2_save) % size].key = key;
				arr[(h_index + h_2_save) % size].present = 1;

			}
		}
	}
	void update(int key, int new_val)
	{
		int h_i = hash_func(key);
		if (c_method == 1)
		{
			while (arr[h_i].key != key)
			{
				h_i++;
			}
			arr[h_i].value = new_val;
		}
		else if (c_method == 2)
		{
			int j = 0;
			int v = 0;
			while (arr[(h_i + v) % size].key != key)
			{
				v++;
				j++;
				v = call_probing(key, j);
			}
			arr[(h_i + v) % size].value = new_val;
		}
		else if (c_method == 3)
		{

		}
		else if (c_method == 4)
		{
			int time = 0;
			int h_2_save = hash_func_2(key);
			h_2_save = time * h_2_save;
			while (arr[(h_i + h_2_save) % size].key != key)
			{
				time++;
				h_2_save = hash_func_2(key);
				h_2_save = time * h_2_save;
			}
			arr[(h_i + h_2_save) % size].value = new_val;
		}
	}
	void deletion(int key)
	{
		int h_i = hash_func(key);
		if (c_method == 1)
		{
			while (arr[h_i].key != key)
			{
				h_i++;
			}
			arr[h_i].value = -1;
			arr[h_i].key = 0;
			arr[h_i].present = 0;
		}
		else if (c_method == 2)
		{
			int j = 0;
			int v = 0;
			while (arr[(h_i + v) % size].key != key)
			{
				v++;
				j++;
				v = call_probing(key, j);
			}
			arr[(h_i + v) % size].value = -1;
			arr[(h_i + v) % size].key = 0;
			arr[(h_i + v) % size].present = 0;

		}
		else if (c_method == 3)
		{

		}
		else if (c_method == 4)
		{
			int time = 0;
			int h_2_save = hash_func_2(key);
			h_2_save = time * h_2_save;
			while (arr[(h_i + h_2_save) % size].key != key)
			{
				time++;
				h_2_save = hash_func_2(key);
				h_2_save = time * h_2_save;
			}
			arr[(h_i + h_2_save) % size].value = -1;
			arr[(h_i + h_2_save) % size].key = 0;
			arr[(h_i + h_2_save) % size].present = 0;
		}
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i].value << " ";
		}
	}
};
int main()
{
	//HashTable any(1, 1);
	//any.insertion(0,10);
	//any.insertion(10,30);
	//any.insertion(5,20);
	//any.insertion(15,40);
	//any.insertion(20,88);
	//any.insertion(25,99);
	///*any.insertion(35,100);
	//any.insertion(45,120);
	//any.insertion(55,140);*/
	//any.display();
	//any.update(20, 100);
	//any.deletion(25);
	//cout << endl;
	//any.display();
	//HashTable some(1, 2);
	//some.insertion(0, 10);
	//some.insertion(10, 30);
	//some.insertion(5, 20);
	//some.insertion(15, 40);
	//some.insertion(20, 88);
	//some.insertion(25, 99);
	///*any.insertion(35,100);
	//any.insertion(45,120);
	//any.insertion(55,140);*/
	//some.display();
	//some.update(20, 100);
	//some.deletion(25);
	//cout << endl;
	//some.display();

	HashTable some(1, 4);
	some.insertion(0, 10);

	some.insertion(10, 30);

	some.insertion(5, 20);

	some.insertion(15, 40);

	some.insertion(20, 88);
	some.display();
	cout << endl;
	some.insertion(25, 99);
	/*any.insertion(35,100);
	any.insertion(45,120);
	any.insertion(55,140);*/
	some.display();
	cout << endl;
	some.update(20, 100);
	some.deletion(25);
	cout << endl;
	some.display();

}