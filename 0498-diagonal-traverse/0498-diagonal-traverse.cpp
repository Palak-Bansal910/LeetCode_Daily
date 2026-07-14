class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans(m*n,0);
        int i = 0, j = 0;
        for(int k = 0; k < m*n; k++){
            ans[k] = mat[i][j];
            if((i+j)%2 == 0){
                if(j == n -1) i++;
                else if(i == 0) j++;
                else{
                    i--; j++;
                }
            }else{
                if(i == m -1) j++;
                else if(j == 0) i++;
                else{
                    i++; j--;
                }
            }
        }
        return ans;
    }
};