class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int sum = 0;
        int min_length = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= target){
                int size = i - j + 1;
                min_length = min(size, min_length);
                sum = sum - nums[j];
                j++;
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};