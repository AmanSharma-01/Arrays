class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int maxR=0, lastIndex=0;
        for(int i=0;i<n;i++) {
            maxR = max(maxR, nums[i]+i);
            if(lastIndex==i && i != n-1) {
                lastIndex=maxR;
                ans++;
            }
        }
        return ans;
        
        // int n = nums.size();
        // vector<int> dp(n, INT_MAX-1);
        // dp[0]=0;
        // for(int i=0;i<n;i++) {
        //     for(int j=i+1;j<=nums[i]+i&&j<n;j++) {
        //         dp[j] = min(dp[j], dp[i]+1);
        //     }
        // }
        // return dp[n-1];
    }
};