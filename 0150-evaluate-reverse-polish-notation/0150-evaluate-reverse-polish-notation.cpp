class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<long long> st;
        for(int i=0;i<n;i++) {
            if(t[i] == "+" || t[i] == "-" || t[i] == "*" || t[i] == "/") {
                long long o2 = st.top();st.pop();
                long long o1 = st.top();st.pop();
                
                switch(t[i][0]) {
                    case '+' : st.push(o1+o2);break;
                    case '-' : st.push(o1-o2);break;
                    case '*' : st.push(o1*o2);break;
                    case '/' : st.push(o1/o2);break;
                }
            } else {
                st.push(stoi(t[i]));
            }
        }
        
        return st.top();
    }
};