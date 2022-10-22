class Solution {
public:
    
//     int getNum(int num) {
//         int sum=0;
//         while(num>0) {
//             int d = num%10;
//             sum+=d;
//             num=num/10;
//         }
//         return sum;
//     }
    
    int addDigits(int num) {
        if(num == 0) return 0;
        else if(num%9 == 0) return 9;
        else return num%9;
        // if(num < 10) return num;
        // return addDigits(getNum(num));
    }
};