bool compare(vector<int>& a, vector<int>& b) {
    return a[0]==b[0] ? a[1]>b[1] : a[0]<b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), compare);
        vector<int> res;
        
        for(auto e: env) {
            int l=0, h=res.size(), mid;
            
            while(l<h) {
                mid = l + (h-l)/2;
                if(res[mid] < e[1]) l = mid+1;
                else h = mid;
            }
            if(h == res.size()) res.push_back(e[1]);
            else res[h] = e[1];
        }
        
        return res.size();
    }
};