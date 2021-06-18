//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(int arr[][4], int n, int m, int k)
{
    //check if empty return false.
    int i=0,j=m-1;

    while(i<n && j>=0)
    {
        if(arr[i][j] < k) i++;
        else if(arr[i][j] > k) j--;
        else return true;
    }
    return false;
}

int main()
{
    int arr[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int n=3,m=4;
    int k = 16;
    bool a = searchMatrix(arr,n,m,k);
    cout<<a<<"\n";
}