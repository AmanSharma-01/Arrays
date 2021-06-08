#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[11] = {-12, 11, -13, -5,-6, -7, 5, -3, 1,-1,8};
    int n = 11;

    int i =0, j = n-1;

    for(i,j;i<n/2&&j>n/2;i++,j--)
    {
        while(arr[i]<0)i++;
        while(arr[j]>=0)j--;

        swap(arr[i],arr[j]);
    }

    for(int a = 0; a<n;a++)
    {
        cout<<arr[a]<<" ";
    }

}

//using 2 pointers we swap -ve numbers in front and +ve numbers to the back.