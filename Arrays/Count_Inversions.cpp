// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

#include<bits/stdc++.h>
using namespace std;

int inversioncount(int arr[], int n) //this is a brute force method and it takes O(n^2) time.
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            if(arr[j]<arr[i]) count++;
        }
    }
    return count;
}

int main() 
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int a = inversioncount(arr,n);

    cout<<"the inversion count is  "<<a;
}
