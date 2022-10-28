class Solution {
private: 
    bool isSubset(vector<int>& main, vector<int>& sub) {
        for(int i=0;i<26;i++) {
            if(main[i] < sub[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> count(26, 0);
        for(auto str: words2) {
            vector<int> strCount(26, 0);
            for(auto ch: str) {
                strCount[ch-'a']++;
                count[ch-'a'] = max(count[ch-'a'], strCount[ch-'a']);
            }
        }
        
        for(auto str: words1) {
            vector<int> strCount(26, 0);
            for(auto ch: str) strCount[ch-'a']++;
            if(isSubset(strCount, count))
                ans.push_back(str);
        }
        
        return ans;
    }
};