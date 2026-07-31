class Solution {
public:
    int numTrees(int n) {
        vector<int> C(n+1);
        C[0] = C[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= i -1;j++){
                C[i] += C[j]*C[i-j-1];
            }
        }
        return C[n];
    }
};