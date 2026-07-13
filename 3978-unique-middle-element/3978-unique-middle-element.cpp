class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        unordered_map<int, int> freq;
        for(int i : nums){
            freq[i]++;
        }
        
        int mid = left + (right - left)/2;
        return freq[nums[mid]] == 1;
       
    }
};