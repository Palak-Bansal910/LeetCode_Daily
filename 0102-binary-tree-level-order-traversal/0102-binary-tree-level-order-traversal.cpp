/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //*DFS APPROACH(RECURSION)*
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }

    void solve(TreeNode* root, int currLevel,vector<vector<int>>& result){
        if(root == NULL) return;
        solve(root->left, currLevel+ 1,result);
        result[currLevel].push_back(root->val);
        solve(root->right, currLevel+ 1,result);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = maxDepth(root);
        vector<vector<int>> result(h,vector<int>(0));
        solve(root,0,result);
        return result;
    }
};
// // *BFS Approach(ITERATIVE)*
        // vector<vector<int>> result;
        // if(root == NULL) return result;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     vector<int> temp;
        //     for(int i = 0; i < n; i++){
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         temp.push_back(curr->val);
        //         if(curr->left){
        //             q.push(curr->left);
        //         }
        //         if(curr->right){
        //             q.push(curr->right);
        //         }
        //     }
        //     result.push_back(temp);
        // }
        // return result;