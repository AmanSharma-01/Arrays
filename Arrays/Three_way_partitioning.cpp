// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

#include<bits/stdc++.h>
using namespace std;

void threeWayPartition(int arr[], int n, int a, int b)
{
    int start = 0, end = n-1;
    for(int i=0;i<=end;)
    {
        if(arr[i]<a) 
            swap(arr[i++], arr[start++]);
        else if(arr[i]>b) 
            swap(arr[i], arr[end--]);
        else i++;
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 10, 20);
 
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}