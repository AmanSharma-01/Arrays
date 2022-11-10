class Solution {
private:
    int m, n;
    bool search(vector<vector<char>>& board, string& word, int idx, int r, int c) {
        if(idx == word.size()) return true; // base case 1.
        if(r<0||r>=m||c<0||c>=n||board[r][c] != word[idx]||board[r][c]=='!') return false; // base case 2.
        char ch = board[r][c];
        board[r][c]='!';
        
        bool ans = search(board, word, idx+1, r+1, c) ||
            search(board, word, idx+1, r-1, c) ||
            search(board, word, idx+1, r, c+1) ||
            search(board, word, idx+1, r, c-1);
        
        board[r][c] = ch;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(search(board, word, 0, i, j))
                    return true;
            }
        }
        
        return false;
    }
};