class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> ans;
        vector<pair<int, int>> temp;
        
        for(int i=0;i<m;i++) {
            int low=0,high=n-1;
            while(low<=high) {
                int mid = low + (high-low)/2;
                if(mat[i][mid]) low = mid+1;
                else high=mid-1;
            }
            temp.push_back({low, i});
        }
        sort(temp.begin(), temp.end(), compare);
        
        for(int i=0;i<k;i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};