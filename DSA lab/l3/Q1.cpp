#include <iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* next;

	Node()
	{
		data = 0;
		next = nullptr;
	}

	~Node()
	{
		next=nullptr;
	}
};



class linkedlist 
{
	Node* head;
	Node* tail;

public:
	linkedlist()
	{
		head = nullptr;
		tail = nullptr;
	}

	~linkedlist()
	{
		head=nullptr;
		tail=nullptr;
	}

	void insertathead(int e)
	{
		cout << "\nInsert at Head called\n";
		if (head == nullptr)
		{
			head =tail= new Node;
			head->data = tail->data = e;
			head->next = tail->next = nullptr;
		}
		else
		{
			Node* ptr = new Node;
			ptr->next = head;
			ptr->data = e;
			head = ptr;

			Node* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			tail = temp;
			tail->next = nullptr;
		}
	}

	void insertattail(int e)
	{
		cout << "\nInsert at Tail called\n";
		if (head == nullptr)
		{
			head = tail = new Node;
			head->data = tail->data = e;
			head->next = tail->next = nullptr;
		}
		else
		{
			Node* ptr = new Node;
			ptr->data = e;
			Node* temp = head;

			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			tail = ptr;
			tail->next = nullptr;
		}
	}

	void insertafter(int key, int val)
	{
		cout << "\nInsert After Called\n";
		int flag = 0;
		Node* temp = head;
		Node* ptr = new Node;
		ptr->data = val;
		Node* n = nullptr;
		while (temp->next != nullptr && flag==0)
		{
			if (temp->data == key)
			{
				flag = 1;
				n = temp->next;
				temp->next = ptr;
				ptr->next = n;
				break;
			}
			temp = temp->next;
		}

		if (flag == 0)
		{
			insertattail(val);
		}
	}

	void insertbefore(int key, int val)
	{
		cout << "\nInsert Before Called\n";
		int flag = 0;
		Node* temp = head;
		Node* ptr = new Node;
		ptr->data = val;
		Node* n = nullptr;

		while (temp->next != nullptr && flag == 0)
		{
			if (temp->next->data == key)
			{
				flag = 1;
				n = temp->next;
				temp->next = ptr;
				ptr->next = n;
				break;
			}
			temp = temp->next;
		}

		if (flag == 0)
		{
			insertattail(val);
		}

	}

	void getmax()
	{
		Node* temp = head;
		int max = temp->data;

		while (temp != nullptr)
		{
			if (max < temp->data)
			{
				max = temp->data;
			}
			temp = temp->next;
		}

		cout << "\nThe max element of linked list is: " << max;
	}

	void getmin()
	{
		Node* temp = head;
		int min = temp->data;

		while (temp != nullptr)
		{
			if (min > temp->data)
			{
				min = temp->data;
			}
			temp = temp->next;
		}

		cout << "\nThe min element of linked list is: " << min;
	}

	void getav()
	{
			Node* temp = head;
			float sum = 0;
			float count = 0;
			float av = 0;

			while (temp != nullptr)
			{
				count++;
				sum = sum + temp->data;
				temp = temp->next;

			}

			av = sum/count;

			cout << "\nThe average of linked list is: " << av;
		
	}

	bool isempty()
	{
		cout << "\nIs linked list empty?\nAns: ";
		if (head && tail == nullptr)
			return true;
		else
			return false;
	}

	void size()
	{
		Node* temp = head;
		int count = 0;

		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}

		cout << "\nThe size of the linked list is: " << count;

	}

	void getmid()
	{
		Node* temp = head;
		int count = 0;

		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}
		temp = head;

		int mid = 0;
		count = count / 2;

		for (int i = 0; i <= count && temp!=nullptr; i++)
		{
			if (i == count)
			{
				mid = temp->data;
			}
			temp = temp->next;
		}

		cout << "\nThe middle value of linked list is: " << mid;
	}

	void delathead()
	{
		cout << "\n***Deletion at head***\n";
		head = head->next;
	}

	void delattail()
	{
		cout << "\n***Deletion at tail***\n";
		Node* temp=head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
	}

	void print()
	{
		cout << "\n***DISPLAY***\n";
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void swap(int val1, int val2)
	{
		Node* v1 = head;
		Node* v2 = head;
		Node* temp = nullptr;
		Node* bv1 = head;
		Node* av2 = head;
		Node* after = head;

		for (int i = 1; i < val1; i++)
		{
			bv1 = bv1->next;
		}

		for (int i = 1; i <= val2+1; i++)
		{
			av2 = av2->next;
		}
		after = av2->next;

		for (int i = 1; i <=val1; i++)
		{
			v1 = v1->next;
		}

		for (int i = 1; i <= val2; i++)
		{
			v2 = v2->next;
		}
		
		temp = v1;
		v1 = v2;
		v2 = temp;
		bv1->next = v1;
		v2->next = av2;

		cout << "\n\nAfter swapping: \n";
	

		cout << "***";
		cout << bv1->data<<" ";
		cout << v1->data << " ";
		cout << v2->data << " ";
		cout << av2->data << " ";
		while (after != nullptr)
		{
			cout << after->data<<" ";
			after = after->next;
		}
		cout << " ***";
	}
};

int main()
{
	linkedlist obj;
	obj.insertathead(1);
	obj.insertattail(2);
	obj.insertattail(3);
	obj.insertattail(4);
	obj.insertbefore(9, 5);
	obj.insertattail(6);
	obj.print();
	obj.getmax();
	obj.getmin();
	obj.getav();
	obj.getmid();
	cout << obj.isempty();
	obj.size();
	obj.delathead();
	obj.delattail();
	obj.print();
	obj.swap(1, 2);

}