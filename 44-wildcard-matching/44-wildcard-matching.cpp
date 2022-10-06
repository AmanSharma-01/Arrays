class Solution {
public:
    int n, m;
    
    bool helper(string& s, string& p,int i,int j,vector<vector<int>> &v) {
        if(j==m)
            return (i==n);
        
        if(v[i][j]<0) {
            if(i==n) {
                v[i][j] = (p[j]=='*' && helper(s,p,i,j+1,v));
            } else if(i<n &&  (p[j]==s[i] || p[j]=='?')) {
                v[i][j] =  helper(s,p,i+1,j+1,v);
            } else if(p[j]=='*') {
                v[i][j] = (helper(s,p,i,j+1,v) || helper(s,p,i+1,j,v));
            } else v[i][j] = false;
        }
        return v[i][j];
    }
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        
        if(m==0){
            return (n==0);
        }
        vector<vector<int>> v(n+1,vector<int> (m+1,-1));
        return  helper(s,p,0,0,v);
    }
};
