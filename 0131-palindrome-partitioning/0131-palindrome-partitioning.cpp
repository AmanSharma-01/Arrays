class Solution {
private:
    vector<vector<string>> ans;
    vector<string> curr;
    
    bool isPal(string a) {
        int s=0,e=a.size()-1;
        while(s<e) if(a[s++]!=a[e--]) return false;
        return true;
    }
    
    void recur(string& s, int idx) {
        if(idx==s.size()) {
            ans.push_back(curr);
            return;
        }
        
        string a="";
        for(int i=idx;i<s.size();i++) {
            a+=s[i];
            if(isPal(a)) {
                curr.push_back(a);
                recur(s, i+1);
                curr.pop_back();
            }
        }
        return;
    }
    
public:
    vector<vector<string>> partition(string s) {
        recur(s, 0);
        return ans;
    }
};