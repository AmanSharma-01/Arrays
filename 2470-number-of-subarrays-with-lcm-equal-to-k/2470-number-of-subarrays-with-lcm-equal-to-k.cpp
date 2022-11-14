class Solution {
private:
    long long gcd(long long int a, long long int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }

    // Function to return LCM of two numbers
    long long lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int c = nums[i];
            for(int j=i;j<n;j++) {
                c = lcm(c, nums[j]);
                if(c == k) ans++;
            }
        }
        return ans;
    }
};