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
    vector<int> nodes;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int minDiff = INT_MAX;
        // int currDiff =  0;
        for(int i = 1; i < nodes.size(); i++){
            minDiff = min(minDiff,nodes[i]-nodes[i-1]);
        }
        return minDiff;
    }
};