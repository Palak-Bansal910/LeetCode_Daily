class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        long long int ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans * (n+i)/i;
        }
        return ans/(n+1);
    }
};