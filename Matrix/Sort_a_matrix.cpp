// Given an NxN matrix Mat. Sort all elements of the matrix.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};

    int ar[16] = {-1};
    int k =0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ar[k++] = arr[i][j];
        }
    }
    sort(ar, ar + k);

    k=0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr[i][j] = ar[k++];
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}