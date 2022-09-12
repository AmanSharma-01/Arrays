class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, 0);
        for(int i=0;i<s.size();i++) {
            lastPos[s[i]-'a']=i;
        }
        int maxR=0;
        vector<int> ans;
        int prev=-1;
        for(int i=0;i<s.size();i++) {
            maxR = max(maxR, lastPos[s[i]-'a']);
            if(i == maxR) {
                ans.push_back(i-prev);
                prev = i;
            }
        }
        return ans;
    }
};