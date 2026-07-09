class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        /*Brute Force Approach
        int count = 0;
        for(int i = 0; i < n; i++){
            int currSum = 0;
            for(int j = i; j < n; j++){
                currSum += nums[j];
                if(currSum == k) count++;
            }
        }
        return count;*/
        unordered_map<int,int> map = {{0,1}};
        int count = 0;
        int curr_sum = 0;
        for(int i : nums){
            curr_sum += i;
            if(map.count(curr_sum - k)){
                count += map[curr_sum - k];
            }
            map[curr_sum]++;
        }
        return count;
    }
};