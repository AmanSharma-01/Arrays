// Given a sorted array arr containing n elements with possibly duplicate elements, 
// the task is to find indexes of first and last occurrences of an element x in the given array.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 1, 3, 5, 5, 5, 67, 123, 125 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    int flag =false;
    int mid,low=0,high=n-1;
    vector<int> ans;

    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(arr[mid] == k) 
        {
            flag=true;
            break;
        }
        else if(arr[mid]<k)
        {
            low = mid +1;
        }
        else 
        {
            high = mid-1;
        }
    }
    if(flag == false)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return 0;
    }
    low=mid,high=mid;
    while(arr[low] == k)
    {
        low--;
    }
    while(arr[high] == k)
    {
        high++;
    }
    ans.push_back(low+1);
    ans.push_back(high-1);

    int z=0;
    while(z<2)
    {
        cout<<ans[z]<<" ";
        z++;
    }
}