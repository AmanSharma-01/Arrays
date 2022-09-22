bool compare(vector<int>& a, vector<int>& b) {
    return a[1]==b[1] ? a[0]<b[0] : a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> prev = intervals[0];
        int ans=0;
        
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] < prev[1]) ans++;
            else prev = intervals[i];
        }
        return ans;
    }
};