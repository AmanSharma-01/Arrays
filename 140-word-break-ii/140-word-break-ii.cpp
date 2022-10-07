class Trie {
public:
    Trie* children[26];
    bool isEnding;
    
    Trie() {
        for(int i=0;i<26;i++) {
            children[i]=NULL;
        }
        isEnding=false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) {
                curr->children[ch-'a'] = new Trie();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEnding = true;
    }
    
    bool search(string& word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return curr->isEnding;
    }
    
};

class Solution {
public:
    vector<string> ans;
    
    void dfs(string& s, int idx, string currStr, Trie* root) {
        if(idx == s.size()) {
            ans.push_back(currStr.substr(0, currStr.length()-1));
            return;
        }
        string str;
        for(int i=idx;i<s.size();i++) {
            str += s[i];
            if(root->search(str)) dfs(s, i+1, currStr+str+" ", root);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* root = new Trie();
        for(auto word: wordDict) {
            root->insert(word);
        }
        dfs(s, 0, "", root);
        return ans;
    }
};








