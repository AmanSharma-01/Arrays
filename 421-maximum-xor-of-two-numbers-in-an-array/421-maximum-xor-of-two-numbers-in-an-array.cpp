class Trie {
    public:
    Trie* children[2];
    
    Trie() {
        children[0]=NULL;
        children[1]=NULL;
    }
    
    void insert(int n) {
        Trie* curr = this;
        for(int i=31;i>=0;i--) {
            if(curr->children[n>>i&1] == NULL) {
                curr->children[n>>i&1] = new Trie();
            }
            curr = curr->children[n>>i&1];
        }
    }
    
    int maxXOR(int n) {
        Trie* curr = this;
        int ans=0;
        for(int i=31;i>=0;i--) {
            int bit = n>>i&1;
            if(curr->children[!bit]) {
                curr = curr->children[!bit];
                ans = ans | 1<<i;
            }
            else curr = curr->children[bit];
        }
        return ans;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        
        for(auto n: nums)
            root->insert(n);
        
        int ans = 0;
        for(auto n: nums)
            ans = max(ans, root->maxXOR(n));
        return ans;
    }
};











