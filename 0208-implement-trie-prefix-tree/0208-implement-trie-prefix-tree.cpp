class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for(int i=0;i<26;i++) {
            children[i]=NULL;
        }
        isEnd=false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) {
                curr->children[ch-'a'] = new Trie();
            }
            curr=curr->children[ch-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a'] == NULL) return false;
            curr = curr->children[ch-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(auto ch: prefix) {
            if(curr->children[ch-'a'] == NULL) return false;
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