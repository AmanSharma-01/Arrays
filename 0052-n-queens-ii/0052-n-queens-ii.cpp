class Solution {
public:
    vector<vector<string>> ans;
    
    bool isValid(vector<string>& board, int r, int c) {
        int n = board.size();
        for(int i=0;i<r;i++) if(board[i][c] == 'Q') return false;
        int i=r-1,j=c-1;
        while(i>=0 && j>=0) if(board[i--][j--] == 'Q') return false;
        i=r-1,j=c+1;
        while(i>=0 && j<n) if(board[i--][j++] == 'Q') return false;
        
        return true;
    }
    
    void findPos(vector<string>& board, int row) {
        int n = board.size();
        if(row >= n) {
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++) {
            board[row][i] = 'Q';
            if(isValid(board, row, i)) {
                findPos(board, row+1);
            }
            board[row][i] = '.';
        }
        
        return;
    }
    
    int totalNQueens(int n) {
        string temp = "";
        for(int i=0;i<n;i++) temp+='.';
        vector<string> board(n, temp);
        findPos(board, 0);
        return ans.size();
    }
};