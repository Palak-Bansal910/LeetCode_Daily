class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i : nums){
            total_sum += i;
        }
        int left_sum = 0;
        for(int i = 0; i < n; i++){
            int right_sum = total_sum - left_sum - nums[i];
            if(left_sum == right_sum){
                return i;
            }else{
                left_sum += nums[i];
            }
            
        }
        return -1;
    }
};