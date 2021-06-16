// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

// Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

#include<bits/stdc++.h>
using namespace std;

int smallestSub(int arr[], int n, int k)//this solution have a time complexity of O(n^2).
{
    int min_length = n+1;
    for (int i=0;i<n;i++)
    {
        int currsum = arr[i];
        if(currsum>k) return 1;
        for(int j=i+1;j<n;j++)
        {
            currsum+=arr[j];
            if(currsum > k && j-i+1 < min_length) min_length = j-i+1; 
        }
    }
    return min_length;
}

int smallestSubWithSum(int arr[], int n, int x)//this is a better solution with a time complexity of O(n).
{
    int sum = 0 , min_length = n+1;
    int i=0,j=0;

    while(j<n)
    {
        while(sum<=x && j<n)
        {
            sum+=arr[j++];
        }

        while(sum>x && i<n)
        {
            if(min_length > j-i) min_length = j-i;
            sum -=arr[i++];
        }
    }
    return min_length;
}

int main()
{
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? cout << "Not possible\n" : cout << res1 << endl;

    return 0;
}