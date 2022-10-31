class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans=0;
        int low=0, high=n-1;
        
        while(low < high) { // time:- O(n) and sapce:- O(1).
            if(height[low] <= height[high]) {
                ans = max(ans,height[low]*(high-low));
                low++;
            } else {
                ans = max(ans, height[high]*(high-low));
                high--;
            }
        }
        
        return ans;
        // int area=0;
        // for(int i=0;i<n;i++) { // time:- O(n^2) and space:- O(1).
        //     for(int j=i+1;j<n;j++) {
        //         area = max(area, min(height[i], height[j])* (j-i));
        //     }
        // }
        // return area;
    }
};