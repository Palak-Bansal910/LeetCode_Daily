class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};
