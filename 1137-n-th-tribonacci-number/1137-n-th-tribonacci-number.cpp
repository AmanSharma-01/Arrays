class Solution {
public:
    int tribonacci(int n) {
        long long a=0;
        long long b=1;
        long long c=1;
        
        for(int i=0;i<n;i++) {
            long long d = c+a+b;
            a=b;
            b=c;
            c=d;
        }
        
        return a;
        
        // if(n<2) return n;
        // if(n==2) return 1;
        // return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};