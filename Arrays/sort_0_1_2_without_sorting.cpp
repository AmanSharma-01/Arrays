#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {0,1,2,0,1,1,2,0,2,1};
    int n = 10;

    int c0=0, c1=0,c2=0;
    int j =0;

    for(int i = 0; i<n;i++)
    {
        if(arr[i] == 0) c0++;
        else if (arr[i] == 1) c1++;
        else c2++;
    }

    //cout<<c0<<"  "<<c1<< "  "<<c2<<"\n";

    for(j=0; j<n;j++)
    {
        if(j<c0) arr[j] = 0;
        if(j>c0-1&&j<c0+c1) arr[j] = 1;
        if(j>c0+c1-1) arr[j] = 2;
    }

    for(int i =0; i< n; i++)
    {
        cout<<arr[i]<<" ";
    }

}
