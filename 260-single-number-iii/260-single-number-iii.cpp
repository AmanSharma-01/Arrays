class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long dif = 0;
        for(int i=0;i<n;i++) 
            dif ^= nums[i];
        
        dif &= -dif;
        vector<int> res = {0, 0};
        
        for(int i=0;i<n;i++) {
            if(dif&nums[i]) res[0] ^= nums[i];
            else res[1] ^= nums[i];
        }
        
        return res;
    }
};