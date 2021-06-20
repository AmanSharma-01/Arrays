// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
//expected time complexity is O(n^2).

#include<bits/stdc++.h>
using namespace std;

void findmaxvalue(int arr[][5], int n) // the time complexity of the following is O(n^4).
{
    int max = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int a=i+1;a<n;a++)
            {
                for(int b=j+1;b<n;b++)
                {
                    if(arr[a][b]-arr[i][j] > max) max = arr[a][b]-arr[i][j];
                }
            }
        }
    }
    cout<<"the maximum is "<<max;
}

int findMaxValue(int mat[][5], int N)//time complexity is O(n^2).
{
    int maxValue = INT_MIN;
    int maxArr[5][5];

    maxArr[N-1][N-1] = mat[N-1][N-1];
 
    int maxv = mat[N-1][N-1];
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N-1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N-1][j] = maxv;
    }
 
    maxv = mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }
 

    for (int i = N-2; i >= 0; i--)
    {
        for (int j = N-2; j >= 0; j--)
        {
            if (maxArr[i+1][j+1] - mat[i][j] > maxValue)
            {
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];
            }
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]) );
        }
    }

    for (int i = 0; i <5; i++)
    {
        for (int j = 0; j <5; j++)
        {
            cout<<maxArr[i][j]<<" ";
        }
        cout<<"\n";
    }
 
    cout<<"the maximum is "<<maxValue;
}

int main()
{
    int arr[5][5] = {{ 1, 2, -1, -4, -20 }, { -8, -3, 4, 2, 1 },  { 3, 8, 6, 1, 3 }, { -4, -1, 1, 7, -6 }, { 0, -4, 10, -5, 1 }};
    int n = 5;
    findMaxValue(arr, n);
    return 0;
}

