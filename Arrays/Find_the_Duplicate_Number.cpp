#include<bits/stdc++.h>
using namespace std;

int findDuplicate (int a[], int n)
{
    int sum = ((n-1)*n)/2;
    int total=0;
    for(int i=0;i<n;i++)
    {
        total+=a[i];
    }
    return total - sum;
}

int main ()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,9};
    int s = 10;

    int ans = findDuplicate(a, s);

    cout<<ans<<" ";
}