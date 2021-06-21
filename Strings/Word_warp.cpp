// Given a sequence of words, and a limit on the number of characters that can be put in one line (line width).
// Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. 
// When line breaks are inserted there is a possibility that extra spaces are present in each line. 
// The extra spaces includes spaces put at the end of every line except the last one. 
// The problem is to minimize the following total cost. 
// Total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2. 
#include <bits/stdc++.h>
using namespace std;

void solveWordWrap(int arr[], int n, int k)
{
    int i,j;
    int currlen;
    int dp[n];
    int ans[n];
    int cost;

    dp[n-1] = 0;
    ans[n-1] = n-1;

    for(i=n-2;i>=0;i--)
    {
        currlen = -1;
        dp[i] = INT_MAX;

        for(j=i;j<n;j++)
        {
            currlen += arr[j]+1;
            if(currlen > k)
                break;
            if(j == n-1)
                cost = 0;
            else 
                cost = (k-currlen) * (k-currlen) + dp[j+1];
            if(cost<dp[i])
            {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }
    i=0;
    while(i<n)
    {
        cout<<i+1<<" "<<ans[i]+1<<" ";
        i = ans[i] + 1;
    }
}

int main()
{
    int arr[] = { 3, 2, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int M = 6;
    solveWordWrap(arr, n, M);
    return 0;
}