class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moorey's Booting Algorithm
        int n = nums.size();
        int me = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(me == nums[i]){
                count++;
            }else{
                count--;
            }

            if(count == 0){
                me = nums[i];
                count = 1;
            }
        }
        int count2 = 0;
        for(int i : nums){
            if(me == i) count2++;
        }
        
        return count2 > n/2? me: -1;
        
        /*unordered_map<int, int> m;
        int n = nums.size();
        int majorityElement;
        for(auto i: nums){
            m[i]++;
        }
        for(auto i: m){
            if(i.second > (int)(n/2)){
                majorityElement = i.first;
            }
        }
        return majorityElement;*/
    }
};