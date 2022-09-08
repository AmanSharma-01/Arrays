class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m1 = nums[0];
        int c1 = 1;
        
        for(int i=1;i<nums.size();i++) {
            if(m1 == nums[i]) c1++;
            else if(c1==0) m1=nums[i],c1=1;
            else c1--;
        }
        return m1;
    }
};