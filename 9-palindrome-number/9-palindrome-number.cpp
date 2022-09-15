class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long temp = 0;
        int ref = x;
        while(x > 0) {
            temp = temp*10 + x%10;
            x = x/10;
        }
        
        return ref == temp;
    }
};