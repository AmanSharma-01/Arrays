class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = digits[n-1] == 9 ? 1 : 0;
        if(digits[n-1] == 9) {
            digits[n-1] = 0;
        } else {
            digits[n-1] = digits[n-1]+1;
        }
        
        for(int i=digits.size()-2; i>=0 ;i--) {
            if(digits[i]+carry == 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] = digits[i]+carry;
                carry = 0;
            }
        }
        
        if(carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};