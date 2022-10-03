class Trie {
    public:
    Trie* children[26];
    int cnt;
    
    Trie() {
        for(int i=0;i<26;i++) {
            children[i]=NULL;
        }
        cnt=0;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a']==NULL) {
                curr->children[ch-'a'] = new Trie();
            }
            curr->children[ch-'a']->cnt++;
            curr = curr->children[ch-'a'];
        }
    }
    
    int prefix(string word) {
        Trie* curr = this;
        int ans=0;
        for(auto ch: word) {
            ans += curr->children[ch-'a']->cnt;
            curr = curr->children[ch-'a'];
        }
        return ans;
    }
    
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        int n = words.size();
        vector<int> ans(n, 0);
        for(auto word: words) {
            root->insert(word);
        }
        
        for(int i=0;i<n;i++) {
            ans[i] = root->prefix(words[i]);
        }
        
        return ans;
    }
};












