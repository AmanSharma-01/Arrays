class Solution {
public:
    
    string giveIso(string& a) {
        vector<int> firstPos(26, -1);
        string s = "";
        for(int i=0;i<a.length();i++) {
            if(firstPos[a[i]-'a'] != -1) {
                s += to_string(firstPos[a[i]-'a'])+',';
            } else {
                firstPos[a[i]-'a']=i;
                s += to_string(firstPos[a[i]-'a'])+',';
            }
        }
        return s;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string phash = giveIso(pattern);
        vector<string> ans;
        
        for(auto word: words) {
            string wordHash = giveIso(word);
            if(wordHash == phash) {
                ans.push_back(word);
            }
        }
        
        return ans;
        
    }
};













