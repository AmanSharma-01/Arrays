// Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(int arr[4][4], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>j) swap(arr[i][j], arr[j][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            swap(arr[i][j], arr[i][n-j-1]);
        }
    }
}

void printMatrix(int arr[][4], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int arr[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    int n = 4;

    rotateMatrix(arr, n);
    printMatrix(arr, n);
}