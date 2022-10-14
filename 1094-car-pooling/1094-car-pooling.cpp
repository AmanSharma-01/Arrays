bool compare(vector<int>& a, vector<int>& b) {
    return a[1]<b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), compare);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {end, numOfPas}
        int currPas=0;
        
        for(auto t: trips) {
            while(!q.empty() && q.top().first <= t[1]) {
                currPas -= q.top().second;
                q.pop();
            }
            currPas += t[0];
            if(currPas > capacity) 
                return false;
            q.push({t[2], t[0]});
        }
        
        return true;
    }
};