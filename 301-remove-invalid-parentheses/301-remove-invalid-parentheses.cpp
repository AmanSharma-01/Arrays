class Solution {
public:
    int getMin(string& s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') {
                st.push('(');
            } else if(s[i] == ')') {
                if(st.empty()) {
                    st.push(')');
                } else if(st.top() == ')') {
                    st.push(')');
                } else {
                    st.pop();
                }
            }
        }
        return st.size();
    }
    
    void res(string s, int m, vector<string>& ans, unordered_map<string, int>& st) {
        if(st[s] != 0) {
            return;
        } else {
            st[s]++;
        }
        
        if(m == 0) {
            int mrn = getMin(s);
            if(mrn==0) {
                ans.push_back(s);
            }
            return;
        }
        
        for(int i=0;i<s.size();i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            res(left+right, m-1, ans, st);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int minRemove = getMin(s);
        vector<string> ans;
        unordered_map<string, int> mp;
        res(s, minRemove, ans, mp);
        return ans;
    }
};















