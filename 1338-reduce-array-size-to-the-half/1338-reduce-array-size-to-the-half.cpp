class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int tarsize = (n+1)/2;
        int freq=0;
        int ans=0;
        unordered_map<int, int> mp;
        priority_queue<int> q;
        
        for(auto i: arr) mp[i]++;
        for(auto i: mp) {
            q.push(i.second);
        }
        
        while(!q.empty() && freq<tarsize) {
            freq+=q.top();q.pop();
            ans++;
        }
        
        return ans;
    }
};