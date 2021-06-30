// Given an array nums[] of size n, 
// construct a Product Array P (of same size n) such that P[i] 
// is equal to the product of all the elements of nums except nums[i].

#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-9

void productPuzzle(int arr[], int n)
{
    long double sum =0;
    for(int i=0;i<n;i++)//calculate sum of log of every element
    {
        sum += (long double)log10(arr[i]);
    }

    for(int i=0;i<n;i++)//claculate anti-log of sum except current element
    {
        cout << (int)(EPS + pow((long double)10.00, sum - log10(arr[i])))<< " ";
    }
}

int main()
{
    int nums[] = {10, 3, 5, 6, 2};
    int n = sizeof(nums)/sizeof(nums[0]);
    productPuzzle(nums, n);
    return 0;
}