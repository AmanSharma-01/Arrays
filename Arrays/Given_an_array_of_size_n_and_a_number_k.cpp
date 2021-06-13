// Given an array of size n and a number k, find all elements that appear more than n/k times

#include<bits/stdc++.h>
using namespace std;

void nbyk(int arr[], int n, int k)
{
    map<int,int> m;
    int x = n/k;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    for(auto i: m)
    {
        if(i.second > x)
            cout<<i.first<<"\n";
    }
}

int main()
{
    int arr[] = { 1, 1, 2, 2, 3, 5,4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    nbyk(arr,n,k);
}