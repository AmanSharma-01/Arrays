class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPos(26, -1);
        for(int i=0;i<s.size();i++) {
            lastPos[s[i]-'a']=i;
        }
        vector<int> ans;
        int prev=-1, maxIndex=0;
        
        for(int i=0;i<s.size();i++) {
            maxIndex = max(maxIndex, lastPos[s[i]-'a']);
            if(i == maxIndex) {
                ans.push_back(i-prev);
                prev = i;
            }
        }
        
        return ans;
    }
};