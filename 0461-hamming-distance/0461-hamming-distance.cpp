class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        int ans=0;
        for(int i=0;i<32;i++) {
            c=1<<i;
            bool a = x&c;
            bool b = y&c;
            if(a==0&&b==1) ans++;
            else if(a==1&&b==0) ans++;
        }
        return ans;
    }
};