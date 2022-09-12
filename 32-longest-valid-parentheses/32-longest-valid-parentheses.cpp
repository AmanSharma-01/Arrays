class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        int ans=0;
        st.push({')', -1});
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') st.push({s[i], i});
            else {
                if(st.top().first == '(') st.pop();
                else {
                    st.push({s[i], i});
                }
            }
        }
        st.push({')', s.size()});
        
        while(st.top().second != -1) {
            auto top1 = st.top();st.pop();
            auto top2 = st.top();
            
            ans = max(ans, top1.second-top2.second-1);
        }
        return ans;
    }
};