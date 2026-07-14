class Solution {
public:
    void setRowZeroes(vector<vector<int>>& matrix, int row, int m) {
        for (int j = 0; j < m; j++) {
            matrix[row][j] = 0;
        }
    }

    void setColumnZeroes(vector<vector<int>>& matrix, int col, int n) {
        for (int i = 0; i < n; i++) {
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row(n);
        vector<bool> col(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                   row[i] = true;
                   col[j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};