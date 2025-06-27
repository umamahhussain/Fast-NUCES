#include <iostream>
using namespace std;

void Commas(string& position, int j, int size)
{
    if (size == 0)
        return;
    if (j == 3)
    {
        j = 0;
        position.insert(size, ",");
    }
    Commas(position, j + 1, size - 1);
}


int main()
{
    string value = "123456";
    cout << value << endl;
    Commas(value, 0, 6);
    cout << value << endl;
}