// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include<bits/stdc++.h>
using namespace std;

int countPair(int arr[], int n, int k)//A simple solution is to traverse each element and check if there’s another number in the array which can be added to it to give sum.time complexity O(n^2).
{
    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j] == k) count++;
        }
    }
    return count;
}

int getPair(int arr[], int n, int sum)//this is going to return in O(n) time complexity and O(n) space complexity.
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
        m[arr[i]]++;
    
    int twice_count = 0;

    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
    return twice_count / 2;
}

int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int a = getPair(arr, n, 6);
    cout<<"the nummber of pairs are  "<<a;

}
