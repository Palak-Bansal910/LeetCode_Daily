class Solution {
public:
    int solve(vector<int>& nums,int l, int r){
        if(l == r) return nums[l];
        int left = nums[l] - solve(nums,l+1,r);
        int right = nums[r] - solve(nums,l,r-1);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n-1) >= 0;
    }
};