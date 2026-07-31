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
    vector<TreeNode*> solve(int l, int r){
       vector<TreeNode*> trees;
       if(l > r){
        trees.push_back(NULL);
        return trees;
       }
       for(int i = l; i <= r; i++){
            vector<TreeNode*> lst = solve(l,i-1);
            vector<TreeNode*> rst = solve(i+1,r);
            for (TreeNode* left : lst) {
                for (TreeNode* right : rst) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
       }
       return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) return {};
        return solve(1,n);
    }
};