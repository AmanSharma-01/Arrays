#include <bits/stdc++.h>
using namespace std;

//first method is using simple sorting. time complexity of this method is O(nlog(n))

int KthMinElement(int arr[],int n, int k)
{
    sort(arr, arr +n);

    return arr[k-1];
}

int KthMaxElement(int arr[],int n, int k)
{
    sort(arr, arr +n);

    return arr[n-k];
}

int main()
{
    int arr[10] = {10,33,79,46,18,9,12,1000,56,28};

    int s = sizeof(arr) / sizeof(arr[0]);

    int m = KthMinElement(arr,s,3);
    int a = KthMaxElement(arr,s,2);

    cout<<"3 rd smallest element "<<m<<"\n";
    cout<<"2 nd largest element "<<a<<"\n";
}
//we can do this in less then O(nlog(n)) using min heap
//heap can be created in n time and k min/max element can be found klog(n). so overall time complexity will be O(n+klog(n)).
