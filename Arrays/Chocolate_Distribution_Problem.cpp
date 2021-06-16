// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. 
// Each packet can have a variable number of chocolates. 
// There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m)
{
    if(m==0||n==0) return 0;
    if(m>n) return -1;
    int mini = INT_MAX;

    sort(arr, arr +n);

    for(int i=0;i+m-1<n;i++)
    {
        if(arr[i+m-1] - arr[i] < mini) mini = arr[i+m-1] - arr[i];
    }
    return mini;

}

int main() 
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}