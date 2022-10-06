class Solution {
public:
    int n,m;
    
    bool dfs(string& s, string& p, int i, int j) {
        if(i>=n && j>=m) return true;
        if(j>=m) return false;
        
        bool temp = i<n && (s[i]==p[j] || p[j]=='.');
        
        if(j+1<m && p[j+1]=='*') {
            bool t1 = dfs(s, p, i, j+2);
            bool t2 = false;
            if(temp) {
                t2 = dfs(s, p, i+1, j);
            }
            return t1||t2;
        } else if(temp) {
            return dfs(s, p, i+1, j+1);
        }
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        n=s.size(),m=p.size();
        return dfs(s, p, 0, 0);
    }
};