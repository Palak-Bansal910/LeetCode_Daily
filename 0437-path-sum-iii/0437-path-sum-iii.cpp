/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<long long, int> prefix;
    int ans = 0;
    void solve(TreeNode* root,long long currSum, int target){
        if(root == NULL) return;
        currSum += root->val;
        if(prefix.count(currSum - target))
            ans += prefix[currSum - target];
        prefix[currSum]++;

        solve(root->left,currSum,target);
        solve(root->right,currSum,target);
        prefix[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum){
        prefix[0] = 1;
        solve(root, 0, targetSum);
        return ans;
    }
};
