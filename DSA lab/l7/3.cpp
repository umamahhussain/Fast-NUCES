//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
//char* delete_duplicates(char* array,int s,int i)
//{
//    if (i==s-1)
//        return array;
//
//    if (array[i] == array[i+1])
//    {
//        int j = 0;
//        while (j!=s-1)
//        {
//            array[j] = array[j + 1];
//            j++;
//        }
//        delete_duplicates(array,s,i++);
//    }
//    delete_duplicates(array + 1,s,i++);
//}
//
//int main()
//{
//    char* name;
//    int s = 0;
//    cout << "\nEnter Size: ";
//    cin >> s;
//    name = new char[s];
//    for (int i = 0; i < s; i++)
//    {
//        cin >> name[i];
//    }
//   cout<<* delete_duplicates(name,s,0);
//}