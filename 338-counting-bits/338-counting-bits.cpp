class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        ans[0]=0;
        for(int i=0;i<=n;i++) {
            ans[i] = ans[i/2]+i%2;
        }
        
        // for(int i=0;i<=n;i++) {
        //     int count=0;
        //     int x = i;
        //     while(x>0) {
        //         count+=x%2;
        //         x = x/2;
        //     }
        //     ans[i]=count;
        // }
        return ans;
    }
};