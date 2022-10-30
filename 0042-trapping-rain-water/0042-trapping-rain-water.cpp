class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans=0;
        int leftMax=0,rightMax=0,left=0,right=n-1;
        
        while(left<=right) {
            if(height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                ans+=leftMax-height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans+=rightMax-height[right];
                right--;
            }
        }
        return ans;
//         vector<int> leftMax(n, 0), rightMax(n, 0);
//         leftMax[0]=height[0];
//         rightMax[n-1]=height[n-1];
//         for(int i=1;i<n;i++) {
//             leftMax[i] = max(leftMax[i-1], height[i]);
//             rightMax[n-1-i] = max(rightMax[n-i], height[n-1-i]);
//         }
        
//         for(int i=0;i<n;i++) {
//             ans += (min(leftMax[i], rightMax[i]) - height[i]);
//         }
//         return ans;
    }
};