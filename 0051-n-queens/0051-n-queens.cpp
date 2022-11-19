class Solution {
private:
    
    bool checkValidPos(vector<string>& board, int r, int c) {
        int n = board.size();
        for(int i=0;i<r;i++) if(board[i][c] == 'Q') return false;
        int i=r-1, j=c-1;
        while(i>=0&&j>=0) if(board[i--][j--] == 'Q') return false;
        i=r-1, j=c+1;
        while(i>=0&&j<n) if(board[i--][j++] == 'Q') return false;
        return true;
    }
    
    void findQueenPos(vector<string>& board, int row, vector<vector<string>>& ans) {
        int n = board.size();
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++) {
            if(checkValidPos(board, row, i)) {
                board[row][i]='Q';
                findQueenPos(board, row+1, ans);
                board[row][i]='.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string temp = "";
        for(int i=0;i<n;i++) {
            temp+='.';
        }
        vector<string> board(n, temp);
        findQueenPos(board, 0, ans); // (board, rowNum, ans vector).
        return ans;
    }
};