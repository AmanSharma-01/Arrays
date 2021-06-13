#include<bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int n)
{
    int mini = arr[0];
    int maxi = arr[0];

    int maxProduct = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            swap(maxi, mini);

        maxi = max(arr[i], maxi * arr[i]);
        mini = min(arr[i], mini * arr[i]);

        maxProduct = max(maxProduct, maxi);
    }

    return maxProduct;
}

int main()
{
    int arr[] = {2, -3, -4, -5, 5, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int a = maxProduct(arr,n);
    cout<<a;
}