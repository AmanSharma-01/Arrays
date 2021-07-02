// C++ program to find kth element 
// from two sorted arrays
#include <bits/stdc++.h>
using namespace std;

int find(int A[], int B[], int m, int n, int k_req) //time complixity of this code is O(k).
{
    int k = 0, i = 0, j = 0;
    while(i < m && j < n)
    {
        if(A[i] < B[j]) 
        {
            k++;
            if(k == k_req) return A[i];
            i++;
        } 
        else
        {
            k++;
            if(k == k_req) return B[j];
            j++;
        }
    }

    while(i < m) 
    {
        k++;
        if(k == k_req) return A[i];
        i++;
    }

    while(j < n) 
    {
        k++;
        if(k == k_req) return B[j];
        j++;
    }
} 

int main()
{
    int A[5] = {100, 112, 256, 349, 770};
    int B[7] = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    
    cout << find(A, B, 5, 7, k);
    
    return 0;
}