class Trie {
public:
    Trie* children[26];
    bool isEnding;
    string s;
    
    Trie()  {
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isEnding = false;
        s = "";
    }
    
    void insert(string word) {
        Trie *curr = this;
        for(auto ch: word) {
            if(curr->children[ch-'a']==NULL) {
                curr->children[ch-'a'] = new Trie();
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEnding = true;
        curr->s = word;
    }
};


class Solution {
public:
    int m,n;
    vector<string> ans;
    
    void dfs(vector<vector<char>>& board, int r, int c, Trie* curr) {
        if(r<0||r>=m||c<0||c>=n||board[r][c]=='@'||curr->children[board[r][c]-'a']==NULL) return;
        curr=curr->children[board[r][c]-'a'];
        
        if(curr->isEnding) {
            ans.push_back(curr->s);
            curr->isEnding = false;
            curr->s="";
        }
        
        char ch = board[r][c];
        board[r][c]='@';
        
        dfs(board, r+1, c, curr);
        dfs(board, r-1, c, curr);
        dfs(board, r, c+1, curr);
        dfs(board, r, c-1, curr);

        board[r][c]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(auto word: words) {
            root->insert(word);
        }
        
        m = board.size();
        n = board[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dfs(board, i, j, root);
            }
        }
        
        return ans;
    }
};












