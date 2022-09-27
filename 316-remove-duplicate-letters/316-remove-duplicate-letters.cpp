class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans = "";
        int n = s.length();
        vector<int> lastPos(26, 0);
        
        for(int i=0;i<n;i++) {
            lastPos[s[i]-'a'] = i;
        }
        stack<int> st;
        vector<bool> vis(26, false);
        
        for(int i=0;i<n;i++) {
            if(vis[s[i]-'a']==false) {
                while(!st.empty() && st.top() >= s[i] && lastPos[st.top()-'a'] > i) {
                    vis[st.top()-'a'] = false;
                    st.pop();
                }
                vis[s[i]-'a']=true;
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};