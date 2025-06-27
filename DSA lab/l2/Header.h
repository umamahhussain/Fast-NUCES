#include <iostream>
using namespace std;

template <typename T>
class ndarr
{
	int dimnum;
	int* dim;
	int size;
	T* arr;

public:
	ndarr()
	{
		dimnum = 0;
		dim = nullptr;
		size = 1;
		arr = nullptr;
	}

	ndarr(int dimensionnum)
	{
		size = 1;
		arr = nullptr;
		dimnum = dimensionnum;
		dim = new int[dimnum];

		cout << "\nEnter the dimensions: ";
		for (int i = 0; i < dimnum; i++)
		{
			cout << "\nDimension " << i + 1 << " : ";
			cin >> dim[i];
		}

		for (int i = 0; i < dimnum; i++)
		{
			this->size = dim[i] * size;
		}
		cout << "\nSize: " << size;
	}

	ndarr(ndarr& obj)
	{
		dimnum = obj.dimnum;
		size = obj.size;
		dim = new int[dimnum];
		for (int i = 0; i < dimnum; i++)
		{
			dim[i] = obj.dim[i];
		}
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	friend istream& operator >>(istream& in, ndarr& obj)
	{
		cout << "\nEnter the elements of the structure: ";
		obj.arr = new T[obj.size];
		for (int i = 0; i < obj.size; i++)
		{
			cin >> obj.arr[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, ndarr& obj)
	{
		cout << "\n\nDISPLAY: \n";
		if (obj.dimnum == 1)
		{
			for (int i = 0; i < obj.size; i++)
			{
				cout << obj.arr[i] << " ";
			}
		}
		else
			if (obj.dimnum == 2)
			{
				for (int i = 0; i < obj.dim[0]; i++)
				{
					for (int j = 0; j < obj.dim[1]; j++)
					{
						cout << obj.arr[i * obj.dim[1] + j] << " ";
					}
					cout << endl;
				}

			}
			else
				if (obj.dimnum == 3)
				{
					cout << "3d\n";
					for (int k = 0; k < obj.dim[0]; k++)
					{
						for (int i = 0; i < obj.dim[1]; i++)
						{
							for (int j = 0; j < obj.dim[2]; j++)
							{
								cout << obj.arr[i * obj.dim[1] * obj.dim[2] + j * obj.dim[2] + k] << " ";
							}
							cout << endl;
						}
						cout << "\n\n";
					}
				}
				else 
					if (obj.
						dimnum > 3)
					{
						for (int i = 0; i < obj.size; i++)
						{
							cout << obj.arr[i] << " ";
						}
					}
		
		return out;
	}


	void Insert(int value, int* location)
	{
		if (dimnum == 3)
		{
			location = new int[3];
			cout << "\nEnter the indexes where you want change: ";
			for (int i = 0; i < 3; i++)
			{
				cin >> location[i];
			}
			int loc = arr[location[0] * dim[1] * dim[2] + location[1] * dim[2] + location[2]];
			arr[loc] = value;
		}
		else
			if (dimnum == 2)
			{
				location = new int[2];
				cout << "\nEnter the indexes where you want change: ";
				for (int i = 0; i < 2; i++)
				{
					cin >> location[i];
				}
				int loc = arr[location[0] * dim[1] + location[1]];
				arr[loc] = value;
			}
			else
			{
				int loc = 0;
				cout << "\nEnter the index where you want change: ";
				cin >> loc;
				arr[loc] = value;
			}
	}


	void remove(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				arr[i] = 0;
			}
		}
	}

	void shrink()
	{
		ndarr temp;
		temp.size = size;
		temp.arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp.arr[i] = arr[i];
		}

		this->size = size / 2;

		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = temp.arr[i];
			cout << arr[i] << " ";
		}
	}

	void Extend()
	{
		ndarr temp;
		temp.size = size;
		temp.arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp.arr[i] = arr[i];
		}

		this->size = size * 2;

		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			if (i >= temp.size)
			{
				arr[i] = 0;
				cout<<arr[i]<<" ";
			}
			else
			{
				arr[i] = temp.arr[i];
				cout<<arr[i]<<" ";
			}
		}
	}

	int& operator[](int n)
	{
		if (n < size)
		{
			return arr[n];
		}
		else
			cout << "\nOut of Bounds";
	}

	int& operator()(int i, int j)
	{
		if (i*j < size)
		{
			return arr[i * dim[1] + j];
		}
		else
			cout << "\nOut of Bounds";
	}

	int& operator()(int i, int j, int k)
	{
		if (i * j*k < size)
		{
			return arr[i * dim[1] * dim[2] + j * dim[2] + k];
		}
		else
			cout << "\nOut of Bounds";
	}

	~ndarr()
	{
		delete dim;
		dim = nullptr;
		delete arr;
		arr = nullptr;
		size = 0;
		dimnum = 0;
	}
};

