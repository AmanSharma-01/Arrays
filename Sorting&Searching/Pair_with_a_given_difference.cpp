// Given an array Arr[] of size L and a number N, 
// you need to write a program to find if there exists 
// a pair of elements in the array whose difference is N.

#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int n, int k)
{
    sort(arr, arr+n);
    int i=0;
    int j=1;
    while(i<n&&j<n)
    {
        if(k == arr[j]-arr[i])
        {
            cout<<"pair is "<<arr[i]<<", "<< arr[j];
            return true;
        }
        else if(k<arr[j]-arr[i]) i++;
        else j++;
    }
    cout<<"no pair found";
    return false;
}

int main()
{
    int arr[] = {5, 20, 3, 2, 50, 80}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int k = 60; 
    findPair(arr, n, k); 
    return 0;
}