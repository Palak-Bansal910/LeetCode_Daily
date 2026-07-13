class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int maxi = 0;
        unordered_map<int,int> state;
        int left = 0, right = 0;
        while(right < nums.size()){
            state[nums[right]]++;
            while(state.size() > 2){
                state[nums[left]]--;
                if(state[nums[left]]==0) state.erase(nums[left]);
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};