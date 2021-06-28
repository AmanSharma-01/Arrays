// Given an array Arr of N positive integers. 
// Your task is to find the elements whose value is equal to that of its index value.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {15, 2, 45, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n;i++)
    {
        if(arr[i] == i+1)
        {
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}