class Trie {
public:
    Trie* children[26];
    bool isEnding;
    Trie() {
        for(int i=0;i<26;i++) children[i]=NULL;
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
    
    bool search(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return curr->isEnding;
    }
    
    bool startsWith(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) {
                return false;
            }
            curr = curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */