class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastPos(26, 0);
        vector<int> vis(26, 0);
        stack<char> st;
        string ans = "";
        for(int i=0;i<s.size();i++) lastPos[s[i]-'a']=i;
        
        for(int i=0;i<s.size();i++) {
            if(vis[s[i]-'a'] == 0) {
                while(!st.empty() && st.top() >= s[i] && lastPos[st.top()-'a'] > i) {
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                vis[s[i]-'a']=1;
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};