#include "Header.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
	fileSystem obj;

	while (1)
	{
		int choice;

		cout << "1. Add Folder\n" << "2. Delete Folder\n" << "3. Add File\n" << "4. Delete File\n" << "5. Read File Contents\n" << "6. List Folder\n";
		cin >> choice;

		if (choice == 1)
			obj.addFldr();
		else if (choice == 2)
			obj.removeFldr();
		else if (choice == 3)
			obj.addFile();
		else if (choice == 4)
			obj.removeFile();
		else if (choice == 5)
			obj.readFile();
		else if (choice == 6)
			obj.listFldr();
		else
			continue;
	}
	return 0;
}