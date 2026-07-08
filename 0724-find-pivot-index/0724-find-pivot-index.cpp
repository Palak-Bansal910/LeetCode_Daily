class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int sumLeft = 0;
            int sumRight = 0;
            for(int j = 0; j < i;j++){
                sumLeft += nums[j];
            }
            for(int j = n -1; j > i; j--){
                sumRight += nums[j];
            }
            if(sumLeft == sumRight){
                return i;
            }
        }
        return -1;
    }
};