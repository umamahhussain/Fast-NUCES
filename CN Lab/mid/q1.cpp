#include <iostream>
using namespace std;
int main()
{
    cout<<"Please enter the elements of the array: ";
    int arr[20];
    int size=0;
    int ans=0;

    for(int i=0;i<20;i++)
    {
        cin>>ans;
        if(ans==-99)
        break;
        else
        {
            arr[i]=ans;
            size++;
        }
    }

    cout<<"\nThe original array is: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

for(int i=0;i<size;i++)
{
    for(int j=i+1;j<size;j++)
    {
        if(arr[i]>arr[j])
        {
            swap(arr[i],arr[j]);
        }
    }
}

cout<<"\nThe modified array is: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }

}