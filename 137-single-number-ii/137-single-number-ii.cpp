class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int c=0, count=0;
        for(int i=0;i<32;i++) {
            c = 1<<i;
            count=0;
            for(auto num: nums) if(num&c) count++;
            if(count%3 == 0) continue;
            ans |= c;
        }
        
        return ans;
    }
};