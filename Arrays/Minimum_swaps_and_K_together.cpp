// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

int minSwap(int *arr, int n, int k) {
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)c++;
    }
    // cout<<c<<"\n";
    int b=0;
    for(int i=0;i<c;i++)
    {
        if(arr[i]>k)b++;
    }

    // cout<<b<<"\n";

    int ans = b;
    // cout<<ans<<"\n";
    for(int i=0,j=c;j<n;i++,j++)
    {
        if(arr[i]>k) b--;
        if(arr[j]>k) b++;

        ans = min(ans,b);
    }
    return ans;
}

int main() {
      
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";
      
    // int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    // n = sizeof(arr1) / sizeof(arr1[0]);
    // k = 5;
    // cout << minSwap(arr1, n, k);
    return 0;
}