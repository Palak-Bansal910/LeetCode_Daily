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
    vector<int> node;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        node.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root){
        inorder(root);
        int n = node.size();
        root->val = node[0];
        root->left = NULL;
        TreeNode* curr = root;
        for(int i = 1; i < n; i++){
            curr->right = new TreeNode(node[i]);
            curr = curr->right;
            curr->left = NULL;
        }
        return root;
    }
};