class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> q;
        string ans = "";
        
        for(auto ch: s) mp[ch]++;
        for(auto i: mp) q.push({i.second, i.first});
        
        while(!q.empty()) {
            int n = q.top().first;
            while(n--) {
                ans += q.top().second;
            }
            q.pop();
        }
        
        return ans;
    }
};