class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> max_prefix(n);
        max_prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            max_prefix[i] = max(max_prefix[i-1],nums[i]);
        }
        int max_sum = INT_MIN;
        for(int j = k; j < n; j++){
            max_sum = max(max_sum, max_prefix[j-k] + nums[j]);
        }
        
        return max_sum;
    }
};