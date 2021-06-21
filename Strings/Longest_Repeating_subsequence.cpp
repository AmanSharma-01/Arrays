// C++ program to find the longest repeating
// subsequence
#include <bits/stdc++.h>
using namespace std;

int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();

    int dp[5][5];//length+1
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1] == str[j-1] && i!=j)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str);
    return 0;
}
