class Solution {
public:
    int ans=0;
    
    void dfs(vector<int> nums, int idx) {
        if(idx==0) {
            ans++;
            return;
        }
        
        for(int i=idx;i>0;i--) {
            swap(nums[i], nums[idx]);
            if(nums[idx]%idx==0 || idx%nums[idx]==0) 
                dfs(nums, idx-1);
            swap(nums[i], nums[idx]);
        }
        
    }
        
    int countArrangement(int n) {
        vector<int> nums(n+1, 0);
        for(int i=1;i<=n;i++) nums[i]=i;
        dfs(nums, n);
        return ans;
    }
};