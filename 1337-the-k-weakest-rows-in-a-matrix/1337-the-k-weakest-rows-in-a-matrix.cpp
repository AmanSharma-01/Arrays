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
            int numOfSol=0;
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 1) numOfSol++;
                else break;
            }
            temp.push_back({numOfSol, i});
        }
        sort(temp.begin(), temp.end(), compare);
        
        for(int i=0;i<k;i++) {
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};