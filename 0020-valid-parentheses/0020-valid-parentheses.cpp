class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++) {
            if(s[i] == '(') st.push(')');
            else if(s[i] == '{') st.push('}');
            else if(s[i] == '[') st.push(']');
            else {
                if(st.empty() || st.top() != s[i]) return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};