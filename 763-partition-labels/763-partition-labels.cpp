class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> lastPos(26, 0);
        for(int i=0;i<s.size();i++) 
            lastPos[s[i]-'a']=i;
        
        int prev=-1,maxR=0;
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