class Solution {
public:
    int calculate(string s) {
        int ans=0;
        int n = s.size();
        if(n == 0) return ans;
        stack<int> st;
        int currNumber = 0;
        char op = '+';
        
        for(int i=0;i<n;i++) {
            char currChar = s[i];
            if(isdigit(currChar)) {
                currNumber = (currNumber*10) + (currChar-'0');
            }
            
            if(!isdigit(currChar) && !iswspace(currChar) || i == n-1) {
                if(op == '+') {
                    st.push(currNumber);
                }
                else if(op == '-') {
                    st.push(-currNumber);
                }
                else if(op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top*currNumber);
                }
                else if(op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top/currNumber);
                }
                currNumber = 0;
                op = currChar;
            }
        }
        
        while(!st.empty()) {
            ans += st.top();st.pop();
        }
        return ans;
    }
};