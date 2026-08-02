class Solution {
public:
    // int solve(vector<int>& piles,int l,int r){
    //     if(l == r) return piles[l];
    //     int left = piles[l] - solve(piles,l+1,r);
    //     int right = piles[r] - solve(piles,l,r-1);
    //     return max(left,right);
    // }
    bool stoneGame(vector<int>& piles) {
        // int n = piles.size();
        // return solve(piles,0,n-1) >= 0;
        return true;
    }
};