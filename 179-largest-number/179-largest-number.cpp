bool compare(string a, string b) {
    return a+b > b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string ans="";
        for(auto num : nums)
            temp.push_back(to_string(num));
        
        sort(temp.begin(), temp.end(), compare);
        for(auto st: temp)
            ans += st;
        
        return ans[0] == '0' ? "0" : ans;
    }
};