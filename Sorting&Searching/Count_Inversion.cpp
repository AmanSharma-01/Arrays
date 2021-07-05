// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) 
// the array is from being sorted. If array is already sorted then the inversion count is 0. 
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

#include<bits/stdc++.h>
using namespace std;

int merge1(int a[],int temp[], int left, int mid, int right)
{
    int i,j,k,inv = 0;
    i=left;
    j=mid;
    k=left;

    while((i<=mid-1) && (j<=right))
    {
        if(a[i]<=a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            inv += mid-i;
        }
    }
    while(i<=mid-1)
    {
        temp[k++] = a[i++];
    }
    while(j<=right)
    {
        temp[k++] = a[j++];
    }
    for(int m=left;m<=right; m++)
    {
        a[m] = temp[m];
    }
    return inv;
}

int megreSort(int a[],int temp[], int left, int right)
{
    int inv =0;
    if(left<right)
    {
        int mid = (left+right) / 2;
        inv += megreSort(a,temp,left, mid);
        inv += megreSort(a,temp,mid+1,right);
        inv += merge1(a,temp,left,mid+1,right);
    }
    return inv;
}

int main()
{
    int a[] = {3,5,2,1,8,6,4,9};
    int n = sizeof(a)/sizeof(a[0]);

    int temp[n];
    cout<< megreSort(a,temp,0,n-1);
    return 0;
}