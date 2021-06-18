//print a matrix in a spiral.
#include<bits/stdc++.h>
using namespace std;

void pSpiral(int arr[][4], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-i;j++) cout<<arr[i][j]<<" ";
        for(int j=i+1;j<n-i;j++) cout<<arr[j][n-i-1]<<" ";
        for(int j=n-i-2;j>=i;j--) cout<<arr[n-i-1][j]<<" ";
        for(int j=n-i-2;j>i;j--) cout<<arr[j][i]<<" ";
    }
}

int main()
{
    int arr[4][4]  = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n =4;
    pSpiral(arr,n);
}