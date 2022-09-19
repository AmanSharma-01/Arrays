class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++) {
            if(nums[i]==1) sum+=nums[i];
            else if(nums[i]==0) sum += -1;
            
            if(sum == 0) ans = max(ans, i+1);
            
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i-mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        
        return ans;
        
        
//         int oneCount=0, zeroCount=0;
//         int n = nums.size();
//         int len=0;
        
//         for(int i=0;i<n;i++) {
//             oneCount = 0, zeroCount=0;
//             for(int j=i;j<n;j++) {
//                 if(nums[j]==0) zeroCount++;
//                 else if(nums[j]==1) oneCount++;
                
//                 if(oneCount == zeroCount) {
//                     len = max(len, j-i+1);
//                 }
                
//             }
//         }
//         return len;
    }
};