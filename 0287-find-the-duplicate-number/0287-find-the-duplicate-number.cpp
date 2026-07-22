class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for(int bit = 31;bit>=0;bit--){
            int m = 1<<bit; //bit masking
            int a =0, e=0;
            for(int i = 1;i < n;i++){
                if((i&m)) a++;
            }
            for(int i : nums){
                if((i&m)) e++;
            }
            if(a < e) result += (1<<bit);
        }
        return result;
    }
};
// *Swap Sort*
    //     int i = 0;
    //     while (i < nums.size()) {
    //         if (nums[i] != i + 1) {
    //             int correct = nums[i] - 1; //check for a correct place of the index 
    //             if (nums[i] == nums[correct]) {//if not at the correct place then return that value becuase is duplicate value
    //                 return nums[i];
    //             }
    //             swap(nums[i], nums[correct]);
    //         } else {
    //             i++;
    //         }
    //     }
    //     return -1;
    // }
// *Floyd Hare Tortoise Method*
        // int slow = nums[0];
        // int fast = nums[0];

        // do {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // } while (slow != fast);

        // slow = nums[0];

        // while (slow != fast) {
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }

        // return slow;