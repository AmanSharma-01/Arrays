class Solution {
public:
    
    string countSort(string& s) {
        vector<int> dp(26, 0);
        for(auto ch: s) dp[ch-'a']++;
        string ans="";
        for(int i=0;i<26;i++) {
            ans += string(i+'a', dp[i]);
        }
        return ans;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for(int i=0;i<strs.size();i++) {
            // string str = strs[i];
            // sort(strs[i].begin(), strs[i].end());
            mp[countSort(strs[i])].push_back(strs[i]);
        }
        
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};