// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
#include<bits/stdc++.h>
using namespace std;

bool sumiszero(int a[], int n)
{
    set<int> sumSet;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;
        sumSet.insert(sum);
    }
    return false;
}

int main()
{
    int a[] = {4, -3, -1, 6};
    int n = sizeof(a) / sizeof(a[0]);
    bool x = sumiszero(a,n);

    cout<<"the sum is zero  "<<x;
}