class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for(int i=0;i<strs.size();i++) {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(str);
        }
        
        for(auto i: mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};