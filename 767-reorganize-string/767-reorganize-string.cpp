class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> mp;
        string ans = "";
        int n = s.size();
        for(auto ch: s) mp[ch]++;
        for(auto i: mp) q.push({i.second, i.first});
        
        if(q.top().first > (n+1)/2) return "";
        
        while(!q.empty()) {
            auto top1 = q.top();q.pop();            
            ans += top1.second;
            top1.first--;
            
            if(!q.empty()) {
                 auto top2 = q.top();q.pop();
                 ans += top2.second;
                 top2.first--;
                 if(top2.first > 0) q.push({top2.first, top2.second});
            }
            if(top1.first > 0) q.push({top1.first, top1.second});
        }
        return ans;
    }
};