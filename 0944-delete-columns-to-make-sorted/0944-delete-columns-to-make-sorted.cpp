class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); // number of words
        int m = strs[0].size(); // length of the single word
        int ans=0;
        
        for(int i=0;i<m;i++) {
            int prev = -1;
            for(int j=0;j<n;j++) {
                if(prev > strs[j][i]-'a') {
                    ans++;
                    break;
                }
                prev = strs[j][i]-'a';
            }
        }
        
        return ans;
    }
};