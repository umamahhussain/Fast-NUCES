#pragma once
#ifndef Header_H
#define Header_H

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class file 
{
private:
	char fileName[15];
	char contents[500];
public:
	void createFile();
	char* getFileName()
	{
		return fileName;
	}
	void outputContents();
};

class folder
{
private:
	file* fileArr;
	folder* subFldr;
	int totalFile;
	int totalSubFldr;
	char fldrName[15];
public:
	folder();
	void createFldr(char[], int, int);
	void deleteFldr(char[], int, int);
	void toAddFile(char[], int, int);
	void toRemoveFile(char[], int, int);
	void toReadFile(char[], int, int);
	void toListFldr(char[], int, int);
};

class fileSystem
{
private:
	folder root;
public:
	void addFldr();
	void removeFldr();
	void addFile();
	void removeFile();
	void readFile();
	void listFldr();
};

void fileSystem::addFldr()
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) 
	{
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) 
		{
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag)
		{
			for (int i = 0; i < size; i++) 
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 1) {
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else 
			{
				check = true;
				root.createFldr(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

folder::folder()
{
	totalFile = 0;
	totalSubFldr = 0;
	fileArr = nullptr;
	subFldr = nullptr;
}

void folder::createFldr(char path[], int size, int n) 
{
	if (n == 0)
	{
		if (totalSubFldr == 0) 
		{
			totalSubFldr++;
			subFldr = new folder[totalSubFldr];
			cout << "Enter Name of Folder: ";
			cin.getline(subFldr[0].fldrName, 15);
		}
		else 
		{
			folder* temp = new folder[totalSubFldr];
			int tempSize = totalSubFldr;
			for (int i = 0; i < totalSubFldr; i++)
				temp[i] = subFldr[i];
			totalSubFldr++;
			subFldr = new folder[totalSubFldr];
			for (int i = 0; i < tempSize; i++)
				subFldr[i] = temp[i];
			cout << "Enter Name of Folder: ";
			cin.getline(subFldr[tempSize].fldrName, 15);
		}
	}
	else 
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--)
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';
		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}
		int index = 0;
		bool exists = false;
		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			if (strcmp(subFldr[i].fldrName, subName) == 0) 
			{
				index = i;
				exists = true;
			}
		}
		if (exists)
		{
			if (subFldr[index].totalSubFldr == 0)
			{
				subFldr[index].totalSubFldr++;
				subFldr[index].subFldr = new folder[subFldr[index].totalSubFldr];
				cout << "Enter Name of Folder: ";
				cin.getline(subFldr[index].subFldr[0].fldrName, 15);
			}
			else
			{
				folder* temp = new folder[subFldr[index].totalSubFldr];
				int tempSize = subFldr[index].totalSubFldr;
				for (int i = 0; i < subFldr[index].totalSubFldr; i++)
					temp[i] = subFldr[index].subFldr[i];
				subFldr[index].totalSubFldr++;
				subFldr[index].subFldr = new folder[subFldr[index].totalSubFldr];
				for (int i = 0; i < tempSize; i++)
					subFldr[index].subFldr[i] = temp[i];
				cout << "Enter Name of Folder: ";
				cin.getline(subFldr[index].subFldr[tempSize].fldrName, 15);
			}
		}
		else 
		{
			cout << "Subfolder does not exist\n";
		}
	}
	cout << totalSubFldr << endl;
	for (int i = 0; i < totalSubFldr; i++)
	{
		cout << subFldr[i].totalSubFldr << " ";
	}
	cout << endl;
}

void fileSystem::removeFldr() 
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) 
	{
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) 
		{
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag) 
		{
			for (int i = 0; i < size; i++)
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 2) 
			{
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else 
			{
				check = true;
				root.deleteFldr(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

void folder::deleteFldr(char path[], int size, int n) 
{
	if (n == 1) 
	{
		if (totalSubFldr == 0)
		{
			cout << "Folder Does Not Exist\n";
		}
		else 
		{
			char subName[15] = { '\0' };
			int x = 0;
			for (int i = size - 1; path[i] != '/'; i--) 
			{
				subName[x] = path[i];
				x++;
			}
			subName[x] = '\0';
			for (int i = 0; i < x / 2; i++) 
			{
				char temp = subName[i];
				subName[i] = subName[(x - 1) - i];
				subName[(x - 1) - i] = temp;
			}

			int index = 0;
			bool found = false;

			for (int i = 0; i < totalSubFldr && !found; i++) 
			{
				if (strcmp(subFldr[i].fldrName, subName) == 0) 
				{
					index = i;
					found = true;
				}
			}

			if (found) 
			{
				for (int i = index; i < totalSubFldr - 1; i++) 
				{
					subFldr[i] = subFldr[i + 1];
				}

				folder* temp = new folder[totalSubFldr];

				for (int i = 0; i < totalSubFldr; i++)
					temp[i] = subFldr[i];

				totalSubFldr--;
				subFldr = new folder[totalSubFldr];

				for (int i = 0; i < totalSubFldr; i++)
					subFldr[i] = temp[i];
			}
			else
				cout << "Folder Does Not Exist\n";
		}
	}
	else
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--) 
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';

		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}

		int index = 0, subIndex = 0;
		bool exists = false;
		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			for (int j = 0; j < subFldr[i].totalSubFldr && !exists; j++) 
			{
				if (strcmp(subFldr[i].subFldr[j].fldrName, subName) == 0) 
				{
					index = i;
					subIndex = j;
					exists = true;
				}
			}
		}
		if (exists)
		{
			for (int i = subIndex; i < subFldr[index].totalSubFldr - 1; i++)
			{
				subFldr[index].subFldr[i] = subFldr[index].subFldr[i + 1];
			}
			folder* temp = new folder[subFldr[index].totalSubFldr];

			for (int i = 0; i < subFldr[index].totalSubFldr; i++)
				temp[i] = subFldr[index].subFldr[i];

			subFldr[index].totalSubFldr--;
			subFldr[index].subFldr = new folder[subFldr[index].totalSubFldr];
			for (int i = 0; i < subFldr[index].totalSubFldr; i++)
				subFldr[i] = temp[i];
		}
		else 
		{
			cout << "Subfoler does not exist\n";
		}
	}
	cout << totalSubFldr << endl;
	for (int i = 0; i < totalSubFldr; i++)
	{
		cout << subFldr[i].totalSubFldr << " ";
	}
	cout << endl;
}

void fileSystem::addFile() 
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) {
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) {
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag) 
		{
			for (int i = 0; i < size; i++) 
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 1) 
			{
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else 
			{
				check = true;
				root.toAddFile(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

void folder::toAddFile(char path[], int size, int n) 
{
	if (n == 0) 
	{
		if (totalFile == 0) 
		{
			totalFile++;
			fileArr = new file[totalFile];
			fileArr[0].createFile();
		}
		else 
		{
			file* temp = new file[totalFile];
			int tempSize = totalFile;
			for (int i = 0; i < totalFile; i++)
				temp[i] = fileArr[i];

			totalFile++;
			fileArr = new file[totalFile];

			for (int i = 0; i < tempSize; i++)
				fileArr[i] = temp[i];

			fileArr[tempSize].createFile();
		}
	}
	else 
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--)
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';
		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}
		int index = 0;
		bool exists = false;
		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			if (strcmp(subFldr[i].fldrName, subName) == 0) 
			{
				index = i;
				exists = true;
			}
		}
		if (exists) 
		{
			if (subFldr[index].totalFile == 0)
			{
				subFldr[index].totalFile++;
				subFldr[index].fileArr = new file[subFldr[index].totalFile];
				subFldr[index].fileArr[0].createFile();
			}
			else 
			{
				file* temp = new file[subFldr[index].totalFile];
				int tempSize = subFldr[index].totalFile;
				for (int i = 0; i < subFldr[index].totalFile; i++)
					temp[i] = subFldr[index].fileArr[i];
				subFldr[index].totalFile++;
				subFldr[index].fileArr = new file[subFldr[index].totalFile];
				for (int i = 0; i < tempSize; i++)
					subFldr[index].fileArr[i] = temp[i];
				subFldr[index].fileArr[tempSize].createFile();
			}
		}
		else 
		{
			cout << "Subfoler does not exist\n";
		}
	}
	cout << totalFile << endl;
	for (int i = 0; i < totalSubFldr; i++) 
	{
		cout << subFldr[i].totalFile << " ";
	}
	cout << endl;
}

void file::createFile() 
{
	cout << "Enter Name of File: ";
	cin.getline(fileName, 15);
	cout << "Enter Contents of File: ";
	cin.getline(contents, 500);
}

void fileSystem::removeFile() 
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) {
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) 
		{
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag) 
		{
			for (int i = 0; i < size; i++) 
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 2)
			{
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else
			{
				check = true;
				root.toRemoveFile(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

void folder::toRemoveFile(char path[], int size, int n) 
{
	if (n == 1) {
		if (totalFile == 0) {
			cout << "File Does Not Exist\n";
		}
		else {
			char subName[15] = { '\0' };
			int x = 0;
			for (int i = size - 1; path[i] != '/'; i--)
			{
				subName[x] = path[i];
				x++;
			}
			subName[x] = '\0';
			for (int i = 0; i < x / 2; i++) 
			{
				char temp = subName[i];
				subName[i] = subName[(x - 1) - i];
				subName[(x - 1) - i] = temp;
			}
			int index = 0;
			bool found = false;
			for (int i = 0; i < totalFile && !found; i++) 
			{
				if (strcmp(fileArr[i].getFileName(), subName) == 0) 
				{
					index = i;
					found = true;
				}
			}
			if (found) {
				for (int i = index; i < totalFile - 1; i++) 
				{
					fileArr[i] = fileArr[i + 1];
				}
				file* temp = new file[totalFile];
				for (int i = 0; i < totalFile; i++)
					temp[i] = fileArr[i];
				totalSubFldr--;
				fileArr = new file[totalFile];
				for (int i = 0; i < totalFile; i++)
					fileArr[i] = temp[i];
			}
			else
				cout << "File Does Not Exist\n";
		}
	}
	else {
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--)
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';
		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}
		int index = 0, subIndex = 0;
		bool exists = false;
		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			for (int j = 0; j < subFldr[i].totalFile && !exists; j++) 
			{
				if (strcmp(subFldr[i].fileArr[j].getFileName(), subName) == 0) 
				{
					index = i;
					subIndex = j;
					exists = true;
				}
			}
		}
		if (exists) 
		{
			for (int i = subIndex; i < subFldr[index].totalFile - 1; i++) 
			{
				subFldr[index].fileArr[i] = subFldr[index].fileArr[i + 1];
			}
			file* temp = new file[subFldr[index].totalFile];
			for (int i = 0; i < subFldr[index].totalFile; i++)
				temp[i] = subFldr[index].fileArr[i];
			subFldr[index].totalFile--;
			subFldr[index].fileArr = new file[subFldr[index].totalFile];
			for (int i = 0; i < subFldr[index].totalFile; i++)
				fileArr[i] = temp[i];
		}
		else 
		{
			cout << "File does not exist\n";
		}
	}
	cout << totalFile << endl;
	for (int i = 0; i < totalSubFldr; i++) 
	{
		cout << subFldr[i].totalFile << " ";
	}
	cout << endl;
}

void fileSystem::readFile() 
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) {
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) 
		{
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag) 
		{
			for (int i = 0; i < size; i++) 
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 2)
			{
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else 
			{
				check = true;
				root.toReadFile(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

void folder::toReadFile(char path[], int size, int n)
{
	if (n == 1) 
	{
		if (totalFile == 0) 
		{
			cout << "File Does Not Exist\n";
		}
		else 
		{
			char subName[15] = { '\0' };
			int x = 0;
			for (int i = size - 1; path[i] != '/'; i--)
			{
				subName[x] = path[i];
				x++;
			}
			subName[x] = '\0';
			for (int i = 0; i < x / 2; i++)
			{
				char temp = subName[i];
				subName[i] = subName[(x - 1) - i];
				subName[(x - 1) - i] = temp;
			}
			int index = 0;
			bool found = false;
			for (int i = 0; i < totalFile && !found; i++) 
			{
				if (strcmp(fileArr[i].getFileName(), subName) == 0) 
				{
					index = i;
					found = true;
				}
			}
			if (found) 
			{
				fileArr[index].outputContents();
			}
			else
				cout << "File Does Not Exist\n";
		}
	}
	else 
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--) 
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';
		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}
		int index = 0, subIndex = 0;
		bool exists = false;
		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			for (int j = 0; j < subFldr[i].totalFile && !exists; j++)
			{
				if (strcmp(subFldr[i].fileArr[j].getFileName(), subName) == 0)
				{
					index = i;
					subIndex = j;
					exists = true;
				}
			}
		}
		if (exists) 
		{
			subFldr[index].fileArr[subIndex].outputContents();
		}
		else 
		{
			cout << "File does not exist\n";
		}
	}
}

void file::outputContents() 
{
	cout << "File Name: " << fileName << endl;
	cout << "Contents: \n" << contents << endl;
}

void fileSystem::listFldr() 
{
	char path[50];
	int size;
	int n = 0;
	bool check = false;
	while (!check) 
	{
		cout << "Enter Path: ";
		//cin.ignore();
		cin.getline(path, 50);
		size = strlen(path);
		char arr[] = { "root\0" };
		bool flag = false;
		for (int i = 0; arr[i] != 't'; i++) 
		{
			if (path[i] != arr[i])
				flag = true;
		}
		if (!flag) 
		{
			for (int i = 0; i < size; i++) 
			{
				if (path[i] == '/')
					n++;
			}
			if (n > 1) 
			{
				cout << "Too many subfolders, subfolders do not have further subfolders\n";
			}
			else 
			{
				check = true;
				root.toListFldr(path, size, n);
			}
		}
		else 
		{
			cout << "Invalid Directory\n";
		}
	}
}

void folder::toListFldr(char path[], int size, int n) 
{
	cout << "Folders: \n";
	if (n == 0) 
	{
		if (totalSubFldr == 0) 
		{
			cout << "No Folders Exist\n";
		}
		else
		{
			for (int i = 0; i < totalSubFldr; i++)
			{
				cout << subFldr[i].fldrName << endl;
			}
		}
	}
	else
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--) 
		{
			subName[x] = path[i];
			x++;
		}

		subName[x] = '\0';
		for (int i = 0; i < x / 2; i++)
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}

		int index = 0;
		bool exists = false;

		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			if (strcmp(subFldr[i].fldrName, subName) == 0) 
			{
				index = i;
				exists = true;
			}
		}
		if (exists)
		{
			if (subFldr[index].totalSubFldr == 0)
				cout << "No Folder Exist in Subfolder\n";
			else
			{
				for (int i = 0; i < subFldr[index].totalSubFldr; i++)
					cout << subFldr[index].subFldr[i].fldrName << endl;
			}
		}
		else 
		{
			cout << "Subfoler does not exist\n";
		}
	}
	cout << "Files: \n";
	if (n == 0) {
		if (totalFile == 0) 
		{
			cout << "No Files Exist\n";
		}
		else 
		{
			for (int i = 0; i < totalFile; i++)
			{
				cout << fileArr[i].getFileName() << endl;
			}
		}
	}
	else 
	{
		char subName[15] = { '\0' };
		int x = 0;
		for (int i = size - 1; path[i] != '/'; i--)
		{
			subName[x] = path[i];
			x++;
		}
		subName[x] = '\0';

		for (int i = 0; i < x / 2; i++) 
		{
			char temp = subName[i];
			subName[i] = subName[(x - 1) - i];
			subName[(x - 1) - i] = temp;
		}
		int index = 0;
		bool exists = false;

		for (int i = 0; i < totalSubFldr && !exists; i++) 
		{
			if (strcmp(subFldr[i].fldrName, subName) == 0) 
			{
				index = i;
				exists = true;
			}
		}

		if (exists) 
		{
			if (subFldr[index].totalFile == 0)
				cout << "No Files Exist in SubFolder\n";
			else 
			{
				for (int i = 0; i < subFldr[index].totalFile; i++)
					cout << subFldr[index].fileArr[i].getFileName() << endl;
			}
		}
		else
		{
			cout << "Subfoler does not exist\n";
		}
	}
}

//class Date
//{
//	time_t *creat;
//	time_t *lastacc;
//
//public:
//	/*Date()
//	{
//		creat = time(NULL);
//		lastacc = time(NULL);
//	}*/
//
//    time_t creation()
//	{
//		time(creat);
//	}
//
//	time_t lastacc()
//	{
//		time(lastacc);
//	}
//
//};









#endif