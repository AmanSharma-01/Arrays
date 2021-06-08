#include <bits/stdc++.h>
using namespace std;

int maxi(int arr[], int n)
{
    int m = INT_MIN;
    for(int i =0;i<n;i++)
    {
        if(arr[i]>m)m=arr[i];
    }
    return m;
}

int mini(int arr[], int n)
{
    int m = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<m)m=arr[i];
    }
    return m;
}

int main()
{
    int arr[10] = {10,33,79,46,18,9,12,1000,56,28};
    int a = maxi(arr,10);
    cout<<a<<"\n";
    int c = mini(arr,10);
    cout<<c;
}
