#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Books
{
	string booktitle;
	string bookauthor;
	int numofbooks;
	int bookid;

public:
	Books();
	/*~Books();*/
	void settitle();
	void setauthor();
	void setnum();
	void setbookid();
	string gettitle();
	string getauthor();
	int getnum();
	int getid();
};

//constructor
Books::Books()
{
	booktitle = "0";
	bookauthor = "0";
	numofbooks = 0;
	bookid = 0;
}

//destructor
//Books::Books()
//{
//	;
//}

void Books::settitle()
{
	cout << endl << endl;
	cin.ignore();
	cout << "\nPlease enter the title of the book: ";
	getline(cin,booktitle);
	
}

void Books::setauthor()
{
	cout << "\nPlease enter the name of the author: ";
	cin >> bookauthor;

}

void Books::setnum()
{
	cout << "\nPlease enter the number of the books: ";
	cin >> numofbooks;
}

void Books::setbookid()
{
	cout << "\nPlease enter the book id: ";
	cin >> bookid;
}

string Books::getauthor()
{
	cout << "\n\nBook author: " << bookauthor;
	return bookauthor;
}

string Books::gettitle()
{
	cout << "\nBook title: " << booktitle;
	return booktitle;
}

int Books::getid()
{
	cout << "\nBook id: " << bookid;
	return bookid;
}

int Books::getnum()
{
	cout << "\nBook number: " << numofbooks;
	return numofbooks;
}

class Student
{
	string firstname;
	string lastname;
	int rollnum;
	int numofbookissue;
public:
	Student();
	void setrollnum();
	void setfname();
	void setlname();
	void setbooknum();

};

Student::Student()
{
	cout << "\nPlease enter the first name: ";
	cin >> this->firstname;
	cout << "\nPlease enter the last name: ";
	cin >> this->lastname;
	cout << "\nPlease enter roll number: ";
	cin >> this->rollnum;
	cout << "\nNum of book issue: ";
	cin >> this->numofbookissue;
}

class Library
{
	Books* book;
	Student student;
	int i;
public:
	Library();


};

Library::Library()
{
	i=0;
}

void Student::setfname()
{
	cout << "\n\nPlease enter your first name: ";
	cin >> firstname;
}

void Student::setlname()
{
	cout << "\n\nPlease enter your last name: ";
	cin >> lastname;

}

void Student::setrollnum()
{
	cout << "\n\nPlease enter your roll number: ";
	cin >> rollnum;

}

void Student::setbooknum()
{
	cout << "\n\nPlease enter your roll number: ";
	cin >> this->numofbookissue;
}