// You are given an array arr[] of size n. 
// Find the total count of sub-arrays having their sum equal to 0.

#include<bits/stdc++.h>
using namespace std;

int countSubarray(int arr[], int n)
{
    int ans =0;
    int sum =0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(mp.find(sum) != mp.end())
        {
            ans += mp[sum];
        }
        mp[sum]++;
    }
    return ans;
}

int main()
{
    int arr[] = {0,0,5,5,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<countSubarray(arr,n);
    return 0;
}