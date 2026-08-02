class Solution {
public:
    // We have returned true because the no of piles is even and no of stones in every pile is odd, so starting with Alice, in however way she pick she will only end up getting more stones, hence the answer will always be true.
    // The other solution for this problem that shows our understanding is through DP Memoization.
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