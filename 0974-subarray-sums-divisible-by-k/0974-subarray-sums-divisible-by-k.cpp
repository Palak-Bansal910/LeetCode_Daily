class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n = nums.size();
       int count = 0;
       int curr_sum = 0;
       unordered_map<int, int> map= {{0,1}};
       for(int i : nums){
            curr_sum += i;
            int rem = (curr_sum % k + k) % k;
            count += map[rem];
            map[rem]++;
       }
       return count;
    }
};