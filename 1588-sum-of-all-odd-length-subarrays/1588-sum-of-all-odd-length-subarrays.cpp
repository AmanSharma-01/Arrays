class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n = arr.size();
        
        for(int i=0;i<n;i++) {
            ans += ((((n-i)*(i+1))+1)/2) * arr[i];
        }
        
        // for(int i=0;i<n;i++) {
        //     for(int j=i;j<n;j++) {
        //         if((j-i)%2 == 0) {
        //             for(int k=i;k<=j;k++) {
        //                 ans+=arr[k];
        //             }
        //         }
        //     }
        // }
        
        return ans;
    }
};