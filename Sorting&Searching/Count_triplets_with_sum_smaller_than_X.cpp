// Given an array arr[] of distinct integers of size N and a sum value X, 
// the task is to find count of triplets with the sum smaller than the given sum value X.

#include<bits/stdc++.h>
using namespace std;

int countTriplets(int arr[], int n, int sum)
{
    int ans=0;
    sort(arr, arr+n);

    for(int i=0;i<n-2;i++)
    {
        int j=i+1,k=n-1;

        while(j<k)
        {
            if(arr[i]+arr[j]+arr[k]>=sum)
            {
                k--;
            }
            else
            {
                ans+=(k-j);
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof arr / sizeof arr[0];
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}