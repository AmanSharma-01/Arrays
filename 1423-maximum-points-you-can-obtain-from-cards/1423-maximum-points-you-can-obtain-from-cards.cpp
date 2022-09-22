class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size(), ans = 0, sum=0;
        for(int i=0;i<k;i++) sum+=card[i];
        ans = max(ans, sum);
        for(int i=0;i<k;i++) {
            sum -= card[k-1-i];
            sum += card[n-1-i];
            ans = max(ans, sum);
        }
        return ans;
    }
};