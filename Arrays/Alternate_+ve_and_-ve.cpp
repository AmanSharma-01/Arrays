// C++ program to rearrange array in alternating positive & negative items with O(1) extra space
#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    int i =0, j=n-1;
    while(i<j)
    {
        while(i<n-1 && arr[i]>0) i++;
        while(j>=0 && arr[j]<0) j--;

        if(i<j) swap(arr[i],arr[j]);
    }
    int k=0;
    while(k<n && i<n)
    {
        swap(arr[k],arr[i]);
        k=k+2;
        i++;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = {2, 3, -4, -1, 6, -9};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    cout << "Rearranged array is \n";
    printArray(arr, n);
    return 0;
}