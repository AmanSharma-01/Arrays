class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        int ans=0;
        for(auto it: tasks) {
            mp[it]++;
        }
        
        for(auto it: mp) {
            int x = it.second;
            if(x == 1) return -1;
            if(x%3 == 0) {
                ans += x/3;
            }
            if(x%3==1) {
                ans += (x-4)/3+2;
            }
            if(x%3==2) {
                ans += (x-2)/3+1;
            }
        }
        
        return ans;
    }
};