class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(3, 0);
        for(int i: nums){
            map[i]++;
        }
        vector<int> res;
        res.reserve(n);
        for(int i = 0; i <= 2; i++){
            if(map[i] > 0){
                int freq = map[i];
                for(int j = 0; j < freq; j++){
                    res.push_back(i);
                }
            }
        }
        nums = res;
    }
};