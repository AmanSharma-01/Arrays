#include<bits/stdc++.h>
using namespace std;

void mergeArray(int a1[],int a2[],int n,int m)
{
    int i = n-1;
    int j=0;

    for( ;i>=0&&j<m;i--,j++)
    {
        if(a1[i]>=a2[j])
        {
            swap(a1[i], a2[j]);
        }
        else
        {
            break;
        }
    }
    sort(a1,a1+n);
    sort(a2, a2+m);
    
    for(int z = 0;z<n;z++)
    {
        cout<<a1[z]<<" ";
    }
    for(int z = 0;z<m;z++)
    {
        cout<<a2[z]<<" ";
    }
}

int main() {
	int a1[] = {1, 3, 5, 7};
    int a2[] = {0, 2, 6, 8, 9};

    int n = sizeof(a1)/sizeof(a1[0]);
    int m = sizeof(a2)/sizeof(a2[0]);

    mergeArray(a1,a2,n,m);
    return 0;
}