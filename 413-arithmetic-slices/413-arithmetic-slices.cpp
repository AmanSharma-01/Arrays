class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans=0,count=0;
        
        for(int i=0;i<n-1;i++) {
            int gap=nums[i+1]-nums[i];
            count=0;
            for(int j=i+1;j<n;j++) {
                if(nums[j]-nums[j-1]==gap)count++;
                else break;
            }
            if(count>=2)ans+=(count-1);
            // cout<<count<<" \n";
        }
        return ans;
    }
};