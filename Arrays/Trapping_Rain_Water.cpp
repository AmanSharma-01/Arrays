// Given an array arr[] of N non-negative integers representing the height of blocks.
// If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

#include<bits/stdc++.h>
using namespace std;

int maxwater(int arr[], int n)//this is a navie approach hai will take O(n^2).
{
    int water = 0;
    for(int i=1;i<n-1;i++)
    {
        int left = arr[i];
        for(int x=0;x<i;x++)
            left = max(left, arr[x]);

    
        int right = arr[i];
        for(int a = i+1; a<n;a++)
            right = max(right, arr[a]);
        
        water = water + (min(left,right) - arr[i]);
    }
    return water;
}

int findWater(int arr[], int n)//this is the better approach with time complexity of O(n).
{
    int res = 0;
    int l_max = 0, r_max = 0;
    int i=0,j=n-1;

    while(i<j)
    {
        if(arr[i]<arr[j])
        {
            if(arr[i]>l_max) l_max = arr[i];
            else res += l_max - arr[i];
            i++;
        }

        else 
        {
            if(arr[j]>r_max) r_max = arr[j];
            else res+= r_max - arr[j];
            j--;
        }
    }

    return res;
}

int main ()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"the maximum water that can be stored is "<< findWater(arr, n);
    return 0;
}