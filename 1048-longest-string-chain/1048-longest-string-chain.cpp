bool compare(string& a, string& b) {
    return a.length()<b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> mp;
        int ans=0;
        
        for(auto word: words) {
            int res=0;
            for(int i=0;i<word.size();i++) {
                string temp = word.substr(0, i) + word.substr(i+1);
                res = max(res, mp[temp]);
            }
            mp[word] = res+1;
            ans = max(ans, mp[word]);
        }
        return ans;
    }
};