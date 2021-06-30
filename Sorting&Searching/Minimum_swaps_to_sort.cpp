// Given an array of n distinct elements. 
// Find the minimum number of swaps required to sort the array in strictly increasing order.

#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr,
          int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int minSwaps(vector<int> a, int n)
{
    vector<int> temp = a;
    map<int, int> mp;
    int ans =0;

    sort(temp.begin(), temp.end());

    for(int i=0;i<n;i++)
    {
        mp[a[i]] = i;
    }

    for(int i=0;i<n;i++)
    {
        if(a[i] != temp[i])
        {
            ans++;
            int x = a[i];
            swap(a, i, mp[temp[i]]);

            mp[x] = mp[temp[i]];
            mp[temp[i]] = i;
        }
    }
    return ans;
}

int main()
{
    vector <int> a = {101, 758, 315, 730, 472, 619, 460, 479};
  int n = a.size();
  cout << minSwaps(a, n);
}