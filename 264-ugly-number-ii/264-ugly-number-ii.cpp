class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> q;
        set<long> st;
        q.push(1);
        n--;
        while(n--) {
            long top = q.top();q.pop();
            
            if(st.find(top*2) == st.end()) {q.push(top*2);st.insert(top*2);}
            if(st.find(top*3) == st.end()) {q.push(top*3);st.insert(top*3);}
            if(st.find(top*5) == st.end()) {q.push(top*5);st.insert(top*5);}
        }
        
        return q.top();
    }
};