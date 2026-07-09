class Solution {
public:
    void reverse(vector<int> &nums,int i, int j){
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 || k == 0) return;
        k = k % n;
        int i = 0;
        int j = n-k-1;
        int a = j + 1;
        int b = n - 1;
  
        reverse(nums, i, j);
        reverse(nums, a, b);
        reverse(nums, 0, n-1);
    }
};