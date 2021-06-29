// Stickler the thief wants to loot money from a society having n houses in a single line. 
// He is a weird person and follows a certain rule when looting the houses. 
// According to the rule, he will never loot two consecutive houses. 
// At the same time, he wants to maximize the amount he loots. 
// The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. 
// He asks for your help to find the maximum money he can get if he strictly follows the rule. 
// Each house has a[i] amount of money present in it.


#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[1], dp[0]);

    for(int i=2;i<n;i++)
    {
        int x = arr[i] + dp[i-2];
        if(x>dp[i-1])
        {
            dp[i]=x;
        }
        else
            dp[i]=dp[i-1];     
    }
    return dp[n-1];
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    cout<<FindMaxSum(arr, arr.size());
}
