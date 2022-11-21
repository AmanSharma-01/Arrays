class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<n-1;i++) {
            int gap = heights[i+1]-heights[i];
            if(gap>0) {
                q.push(gap);
            }
            if(q.size() > ladders) {
                bricks -= q.top();q.pop();
            }
            if(bricks < 0) {
                return i;
            }
        }
        return n-1;
    }
};