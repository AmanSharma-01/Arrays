class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1, true);
        int ans=0;
        primes[0]=false;
        primes[1]=false;
        
        for(int i=2;i*i<n;i++) {
            if(primes[i]) {
                for(int j=i*i; j<=n;j+=i) {
                    primes[j]=false;
                }
            }
        }
        
        for(int i=2;i<n;i++) {
            if(primes[i]) ans++;
        }
        return ans;
    }
};