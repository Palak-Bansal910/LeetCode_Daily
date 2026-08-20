class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[0] = nums[0];
        arr[n-1] = nums[1];
        int l = 0, r = n-1;
        for(int i = 2; i < n; i++){
            if(arr[l] > arr[r]){
                arr[++l] = nums[i];
            }else{
                arr[--r] = nums[i];
            }
        }
        reverse(arr.begin() + r, arr.end());
        return arr;
    }
};