class Solution {
public:
    int fib(int n) {
        int a=0;
        int b=1;
        int c;
        for(int i=0;i<n;i++) {
            c=a+b;
            a=b;
            b=c;
        }
        return a;
        
        // if(n==0 || n==1) return n;
        // return fib(n-1)+fib(n-2);
    }
};