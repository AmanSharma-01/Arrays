class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int>> freq(26, vector<int>(2, 0));
        int n = s.length();
        for(int i=0;i<n;i++) {
            freq[s[i]-'a'][0]++; // this is the frequency of char.
            freq[s[i]-'a'][1]=i; // this is the last occurance to find the first char.
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<26;i++) {
            if(freq[i][0]==1 && freq[i][1]<ans) {
                ans = freq[i][1];
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};