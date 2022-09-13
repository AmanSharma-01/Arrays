class Solution {
public:
    
    bool isVaild(vector<string>& board, int r, int c) {
        int n = board.size();
        for(int i=0;i<r;i++) if(board[i][c]=='Q') return false;
        int i=r-1,j=c-1;
        while(i>=0&&j>=0) if(board[i--][j--]=='Q') return false;
        i=r-1,j=c+1;
        while(i>=0&&j<n) if(board[i--][j++]=='Q') return false;
        
        return true;
    }
    
    void dfs(vector<string>& board, int row, vector<vector<string>>& ans, int n) {
        if(row >= n) {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++) {
            board[row][i]='Q';
            if(isVaild(board, row, i)) {
                dfs(board, row+1, ans, n);
            }
            board[row][i]='.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string temp = "";
        for(int i=0;i<n;i++) temp+='.';
        vector<vector<string>> ans;
        vector<string> board(n, temp);
        dfs(board, 0, ans, n);
        return ans;
    }
};