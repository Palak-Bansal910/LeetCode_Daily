class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string>& board, int row, int n, int& count){
        if(row == n){
            count++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(isSafe(board,row,i, n)){
                board[row][i] = 'Q';
                nQueens(board,row+1,n,count);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        int count = 0;
        nQueens(board,0,n,count);
        return count;
    }
};