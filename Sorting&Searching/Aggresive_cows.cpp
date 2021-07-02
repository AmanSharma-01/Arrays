// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
//The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
//once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
//such that the minimum distance between any two of them is as large as possible. 
//What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a, a+n);

        int lb =1;
        int ub = 1e9;
        int ans=0;

        while(lb<=ub)
        {
            int mid = (lb + ub)/2;
            int previous_cow_pos = a[0];
            int cow=1;
            for(int i=0;i<n;i++)
            {
                if(a[i] - previous_cow_pos >= mid)
                {
                    cow++;
                    previous_cow_pos = a[i];
                    if(cow == c) break;
                }
            }
            if(cow == c)
            {
                ans = mid;
                lb = mid+1;
            }
            else{
                ub = mid-1;
            }
        }
        cout<<"the minimum distance is "<< ans;
    }
    return 0;
}
