class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string ans="";
        for(int i=0;i<s.length();i++) {
            if(!st.empty() && st.top().first==s[i]) {
                auto top = st.top();st.pop();
                top.second++;
                if(top.second == k) continue;
                st.push(top);
            }
            else st.push({s[i], 1});
        }
        while(!st.empty()) {
            auto top = st.top();
            for(int i=0;i<top.second; i++) {
                ans += top.first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};