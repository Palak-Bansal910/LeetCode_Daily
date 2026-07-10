class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        for(auto i: nums1){
            s.insert(i);
        }
        for(auto i : nums2){
            if(s.count(i) == 1){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};