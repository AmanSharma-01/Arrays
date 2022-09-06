class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low=0, high=n-1;
        int ans=0;
        
        while(low < high) {
            if(height[low] < height[high]) {
                ans = max(ans, height[low]*(high-low));
                low++;
            } else {
                ans = max(ans, height[high]*(high-low));
                high--;
            }
        }
        return ans;
    }
};