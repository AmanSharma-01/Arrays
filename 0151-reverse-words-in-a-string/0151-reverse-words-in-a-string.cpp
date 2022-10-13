class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string ans="";
        
        for(int i=0;i<s.size();i++) {
            string temp="";
            int j=i;
            for(j=i;j<n&&s[j]!=' ';j++) {
                temp+=s[j];
            }
            if(temp.length()) st.push(temp);
            i=j;
        }
        
        while(!st.empty()) {
            ans += st.top()+" ";
            st.pop();
        }
        
        return ans.substr(0, ans.size()-1);
    }
};