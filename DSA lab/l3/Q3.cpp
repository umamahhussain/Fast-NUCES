#include <iostream>
using namespace std;

class Node
{
public:
	char data;
	Node* next;

	Node()
	{
		data = '0';
		next = nullptr;
	}

	~Node()
	{
		next = nullptr;
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
		head = nullptr;
		tail = nullptr;
	}

	void insertathead(char e)
	{
		cout << "\nInsert at Head called\n";
		if (head == nullptr)
		{
			head = tail = new Node;
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

	void insertattail(char e)
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

	void delathead()
	{
		cout << "\n***Deletion at head***\n";
		head = head->next;
	}

	void delattail()
	{
		cout << "\n***Deletion at tail***\n";
		Node* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
	}

	void split()
	{
		int count = 0;
		Node* temp = head;
		while (temp != nullptr)
		{
			count++;
			temp = temp->next;
		}

		int mid = count / 2;

		temp = head;
		int count2 = 0;
		Node* tail1 = new Node;

		cout << "\nFirst List: ";
		while (temp!=nullptr && count2!=mid)
		{
			cout << temp->data << " ";
			count2++;
			temp = temp->next;
		}
		

		int count3 = 0;
		temp = head;
		cout << "\nSecond List: ";
		while (temp != nullptr && mid != count)
		{
			if (count3 == mid || count3 > mid)
			{
				cout << temp->data << " ";
				temp = temp->next;
				count3++;
			}
			else
			{
				temp = temp->next;
				count3++;
			}
		}
	}

	void merge(linkedlist obj,linkedlist obj2)
	{
		Node* temp = obj.head;
		cout << "\nMerging the two linked lists: ";
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		temp = obj2.head;

		
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

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
};

int main()
{
	linkedlist obj;
	obj.insertathead('b');
	obj.insertathead('a');
	obj.insertattail('c');
	obj.insertattail('d');
	obj.insertattail('e');
	obj.insertattail('f');

	obj.print();
	obj.delathead();
	obj.delattail();
	obj.print();
	obj.size();
	obj.split();


	linkedlist obj2;
	obj2.insertathead('g');
	obj2.insertattail('h');
	obj2.insertattail('i');
	obj2.insertattail('j');
	
	cout << "\nNew List: ";
	obj2.print();
	obj2.split();
	obj2.merge(obj,obj2);


		
}

