class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> freq(60, 0);
        int ans=0;
        
        for(int i=0;i<n;i++) {
            int temp = time[i]%60;
            
            if(temp == 0) {
                ans += freq[0];
            } else {
                ans += freq[60-temp];
            }
            freq[temp]++;
        }
        
        return ans;
        
//         int n = time.size();
//         int ans=0;
        
//         for(int i=0;i<n;i++) {
//             for(int j=i+1;j<n;j++) {
//                 if((time[i]+time[j])%60 == 0) ans++;
//             }
//         }
        
//         return ans;
    }
};