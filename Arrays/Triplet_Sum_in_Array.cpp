
#include <bits/stdc++.h>
using namespace std;

bool find(int A[], int n, int sum) //this is the naive approach with a time complexity of O(n^3).
{ 
    int l, r; 
    for (int i = 0; i < n - 2; i++)
    { 
        for (int j = i + 1; j < n - 1; j++)
        { 
            for (int k = j + 1; k < n; k++)
            { 
                if (A[i] + A[j] + A[k] == sum)
                { 
                    cout << "Triplet is " << A[i] <<
                        ", " << A[j] << ", " << A[k]; 
                    return true; 
                } 
            } 
        } 
    } 
    return false; 
}

bool find3Numbers(int A[], int arr_size, int sum)//this is better approach and uses sorting. time complexity is O(n^2).
{
    int l, r;
    sort(A, A + arr_size);
    for (int i = 0; i < arr_size - 2; i++) 
    {
        l = i + 1;
        r = arr_size - 1;
        while (l < r) {
            if (A[i] + A[l] + A[r] == sum) {
                printf("Triplet is %d, %d, %d", A[i],
                       A[l], A[r]);
                return true;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else
                r--;
        }
    }
    return false;
}

int main() 
{ 
    int A[] = {12, 3, 4, 1, 6, 9}; 
    int sum = 24; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
    find3Numbers(A, arr_size, sum); 
    return 0; 
}

