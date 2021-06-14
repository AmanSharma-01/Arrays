// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not.
// Both the arrays can be sorted or unsorted.
// It may be assumed that elements in both array are distinct.

#include <bits/stdc++.h>
using namespace std;

bool isSub(int arr1[], int arr2[],int m, int n) // this is a brute force method with a time complexity of O(n * m).
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == m)
            return 0;
    }
    return 1;
}

bool isSubset(int arr1[], int m,int arr2[], int n) // this is the better approach using hashing and the time complexity of O(m+n).
{
    set<int> s;
    for(int i=0;i<m;i++)
    {
        s.insert(arr1[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(arr2[i]) == s.end()) return 0;
    }
    return 1;
}
 
int main()
{
    int arr1[] = { 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, m,arr2, n))
        cout<<("arr2[] is subset of arr1[] ");
    else
        cout<<("arr2[] is not a subset of arr1[]");
 
    getchar();
    return 0;
}