#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int arr[] = { 10, 22, 5, 75, 65, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int profit  = 0;
    int sum[6]={0};
    int max = 0;
    for(int i=1;i<n;i++)
    {
        int s = arr[i] - arr[i-1];
        int j =i;
        int bsum = 0;

        if(s>0)
        {
            profit+=s;
            while(j>=0)
            { 
                bsum+=sum[j];
                j--;
            }
           sum[i] = profit - bsum; 
        }
        else 
        {
            sum[i] = 0;
        }
    }
    sort(sum, sum + n);
    for(int i =0;i<n;i++)
    {
        cout<<sum[i]<<"  ";
    }
    max = sum[5] + sum[4];
    cout<<"maximum profit that can be achived is  "<<max;

}