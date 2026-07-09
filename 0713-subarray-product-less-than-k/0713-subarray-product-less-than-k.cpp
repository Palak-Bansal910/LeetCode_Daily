class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int j = 0;
        if(k <= 1) return 0;
        int curr_product = 1;
        for(int i = 0; i < n; i++){
            curr_product *= nums[i];
            while(curr_product >= k){
                curr_product /= nums[j];
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }       
    
};