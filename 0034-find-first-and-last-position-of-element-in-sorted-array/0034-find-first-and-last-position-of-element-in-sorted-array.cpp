class Solution {
public:
    int firstOccurence(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                idx = mid;
                right = mid -1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return idx;
    }
    int lastOccurence(vector<int>&nums, int target){
         int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                idx = mid;
                left = mid + 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(firstOccurence(nums,target));
        result.push_back(lastOccurence(nums,target));
        return result;
    }
};