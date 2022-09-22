class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int i=0, j=0;
        
        while(i<f.size() && j< s.size()) {
            int first = max(f[i][0], s[j][0]);
            int second = min(f[i][1], s[j][1]);
            
            if(first <= second) ans.push_back({first, second});
            
            if(f[i][1]<s[j][1]) i++;
            else j++;
        }
        
        return ans;
    }
};