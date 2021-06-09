#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int n,int b[], int m) {
    int s = n+m;
    int c[10];//size of third list must be equal to the sum of the both lists.

    int i=0,j=0,k=0;

    while(i<n && j<m)
    {
        if(a[i]<b[j]) c[k++] = a[i++];
        if(a[i]>b[j]) c[k++] = b[j++];
    }

    for(;i<n;i++)
        c[k++] = a[i++];
    for(;j<m;j++)
        c[k++] = b[j++];

        //for loop for printing the final array.
        for(int q =0;q<10;q++)
        {
            cout<<c[q]<<"  ";
        }
}

int main()
{
    int a[5]={1,3,5,7,9};
    int x=5;
    int b[5]={2,4,6,8,10};
    int y=5;

    merge(a,x,b,y);

}