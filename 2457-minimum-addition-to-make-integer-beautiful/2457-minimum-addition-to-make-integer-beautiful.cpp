class Solution {
private:
    long long digitSum(long long n) {
        long long ans = 0;
        while(n>0) {
            int digit = n%10;
            n = n/10;
            ans += digit;
        }
        return ans;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long org = n;
        if(digitSum(n) <= target) return 0;
        long long temp = 10;
        while(digitSum(n) > target) {
            if(n%temp == 0) temp *=10;
            n = (n/temp+1)*temp;
            temp *= 10;
        }
        
        return n-org;
    }
};