class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos = 31;
        uint32_t reverse = 0;
        while (pos >= 0 && n)
        {
            if (n & 1) {
                reverse = reverse | (1 << pos);
            }
            n>>= 1;
            pos--;
        }
        return reverse;
    }
};