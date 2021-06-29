// Given an array of integers and another number. 
// Find all the unique quadruple from the given array that sums up to the given number.

#include<bits/stdc++.h>
using namespace std;

int find4Numbers(int a[], int n, int x)
{
    sort(a, a+n);
    int l, r;

    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            l = j+1;
            r = n-1;

            while(l<r)
            {
                if(a[i]+a[j]+a[l]+a[r] == x)
                {
                    cout<<"the quad is "<< a[i]<<" "<< a[j]<<" "<< a[l]<<" "<< a[r]<<"\n";
                    l++;
                    r--;
                }
                else if(a[i]+a[j]+a[l]+a[r]<x) l++;
                else r--;
            }
        }
    }
}

int main()
{
    int A[] = {1, 4, 45, 5, 10, 10,0,0};
    int X = 20;
    int n = sizeof(A) / sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}