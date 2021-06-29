// A step array is an array of integers where each element has a difference of at most k with its neighbor. 
// Given a key x, we need to find the index value of x if multiple-element 
// exist to return the first occurrence of the key.
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n)
    {
        if(arr[i] == x)
            return i;
        i = i + max(1, abs(arr[i]-x)/k);
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 2;
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Element " << x  << " is present at index "
         << search(arr, n, x, k);
    return 0;
}