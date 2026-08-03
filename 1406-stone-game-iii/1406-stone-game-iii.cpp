class Solution {
public:
// Using DP Memoizatio, we store the values of current three max which they pick that will add up to their max score and then decides the next state.
    vector<int> dp;
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        if(dp[i] != INT_MIN)
            return dp[i];
        
        int take = 0;
        int ans = INT_MIN;
        for(int j = 0; j < 3 && i+j < nums.size(); j++){
            take += nums[i+j];
            ans = max(ans,take-solve(nums,i+j+1));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& nums) {
        int n = nums.size();
       dp.assign(n,INT_MIN);
       int diff = solve(nums,0);

       if(diff > 0) return "Alice";
       if(diff < 0) return "Bob";

       return "Tie";
    }
};