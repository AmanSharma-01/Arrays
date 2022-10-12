bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[0]-v1[1] < v2[0]-v2[1];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans=0;
        sort(costs.begin(), costs.end(), compare);
        for(int i=0;i<n/2;i++) {
            ans += costs[i][0] + costs[i+n/2][1];
        }
        return ans;
    }
};