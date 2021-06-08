#include <iostream>

using namespace std;

int main() //first method using extra array
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int brr[9] = {0};

    for(int i=0,j=8;i<9&&j>=0;i++,j--)
    {
        brr[i] = arr[j];
    }

    for(int i =0;i<9;i++)
    {
        arr[i] = brr[i];
    }


    for(int i =0;i<9;i++)
    {
        cout<<arr[i]<<"\n";
    }
}

int main() //second method using swaping of elements.
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};

    for(int i = 0, j =8; i<9&&j>=4;i++,j--)
    {
        swap(arr[i],arr[j]);
    }

    for(int i =0;i<9;i++)
    {
        cout<<arr[i]<<"\n";
    }
}
