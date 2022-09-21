class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        int ans=0;
        for(int i=0;i<s.size();i++) {
            mp[s[i]].push_back(i);
        }
        
        for(auto word: words) {
            int x = -1;
            bool found = true;
            for(auto ch: word) {
                auto i = upper_bound(mp[ch].begin(), mp[ch].end(), x);
                if(i == mp[ch].end()) found = false;
                else x = *i;
            }
            if(found) ans++;
        }
        return ans;
    }
};