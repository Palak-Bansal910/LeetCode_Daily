class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int j = 0; j < n; j++){
            nums[j] = pow(nums[j],2);
        }
        vector<int> ans;
        int i = 0;
        int j = n -1;
        while(i <= j){
            if(nums[i] < nums[j]){
                ans.push_back(nums[j]);
                j--;
            }else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        reverse(ans.begin(),ans.end());
        /*for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
        }
            swap(nums[i], nums[minIndex]);
        }*/
        return ans;
    }
};