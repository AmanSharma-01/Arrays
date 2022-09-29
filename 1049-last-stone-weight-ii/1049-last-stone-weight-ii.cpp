class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total=0;
	    for(int i=0;i<n;i++) total+=stones[i];
	    vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));
	    vector<int> temp;
	    int ans=INT_MAX;
	    for(int i=0;i<total+1;i++) dp[0][i]=false;
	    for(int i=0;i<n+1;i++) dp[i][0]=true;
	    
	    for(int i=1;i<n+1;i++) {
	        for(int j=1;j<total+1;j++) {
	            if(stones[i-1] <= j) {
	                dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
	            } else {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    for(int i=0;i<total+1;i++) if(dp[n][i]) temp.push_back(i);
	    int maxs1 = total/2;
	    
	    for(int i=0;i<temp.size()&&temp[i]<=maxs1;i++) {
	        ans = min(ans, total-2*temp[i]);
	    }
	    return ans;
    }
};