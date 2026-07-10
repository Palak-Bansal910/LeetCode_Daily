class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int score = 0;
        int maxScore = 0;
        int j = 0;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            score += nums[i];
            while(s.count(nums[i])){
                score -= nums[j];
                s.erase(nums[j]);
                j++;
            }
            s.insert(nums[i]);
            maxScore = max(maxScore,score);
        }
        return maxScore;
    }
};