// Given an array that represents elements of arithmetic progression in order. 
// One element is missing in the progression, find the missing number. 

#include<bits/stdc++.h>
using namespace std;

int findMissingInAP(int a[],int low,int high,int diff)
{
    if(high<=low) return INT_MAX;

    int mid = (low+high)/2;

    if(a[mid+1] - a[mid] != diff) return (a[mid]+diff);
    if(mid>0 && a[mid]-a[mid-1] != diff) return (a[mid-1]+diff);

    if(a[mid] == a[0]+mid*diff) return findMissingInAP(a,mid+1,high,diff);

    return findMissingInAP(a,low,mid-1,diff);
}


int findMissing(int a[], int n)
{
    int diff = (a[n-1] -  a[0])/n;
    return findMissingInAP(a,0,n-1,diff);
}

int main()
{
    int a[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<findMissing(a,n);
    return 0;
}