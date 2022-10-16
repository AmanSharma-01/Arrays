class Solution {
private:
    int getMin(string& s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                st.push('(');
            } else if(s[i] == ')') {
                if(st.empty()) {
                    st.push(')');
                } else if(st.top()==')') {
                    st.push(')');
                } else if(st.top() == '(') {
                    st.pop();
                }
            }
        }
        return st.size();
    }
    
    void dfs(string s, int remove, vector<string>& ans, unordered_map<string, int>& mp) {
        if(mp[s]) {
            return;
        } else {
            mp[s]++;
        }
        
        if(remove == 0 && getMin(s) == 0) { // base case
            ans.push_back(s);
            return;
        }
        
        for(int i=0;i<s.size();i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            dfs(left+right, remove-1, ans, mp);
        }
        
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int remove = getMin(s);
        dfs(s, remove, ans, mp);
        return ans;
    }
};