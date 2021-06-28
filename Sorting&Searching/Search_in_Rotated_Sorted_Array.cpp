// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is rotated at an unknown pivot index 
// k (0 <= k < nums.length) such that the resulting array is 
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
// For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the rotation and an integer target, 
// return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int k)
{
    int low =0;
    int high = n-1;
    int mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid] == k)
            return mid;

        else if(arr[low]<=arr[mid])
        {
            if(arr[low]<=k && arr[mid]>k)
                high = mid-1;
            else 
                low = mid+1;
        }
        else 
        {
            if(arr[high]>=k && arr[mid]<k)
                low = mid+1;
            else
                high = mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 4;

    cout<<search(arr, n, k);
}