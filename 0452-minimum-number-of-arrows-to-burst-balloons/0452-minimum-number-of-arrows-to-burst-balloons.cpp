bool compare(vector<int>& a, vector<int>& b) {
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), compare);
        int ans=0, yAxis=0;
        
        for(int i=0;i<n;i++) {
            if(ans==0 || points[i][0] > yAxis) {
                ans++;
                yAxis = points[i][1];
            }
        }
        
        return ans;
    }
};