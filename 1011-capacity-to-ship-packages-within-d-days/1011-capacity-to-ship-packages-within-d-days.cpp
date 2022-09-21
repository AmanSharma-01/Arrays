class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans=0;
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            int day = 1;
            int sum = 0;
            for(int i=0;i<weights.size();i++) {
                sum += weights[i];
                if(sum > mid) {
                    sum = weights[i];
                    day++;
                }
            }
            
            if(day <= days) {
                ans = mid;
                high = mid-1;
            } 
            else low = mid+1;
        }
        return ans;
    }
};