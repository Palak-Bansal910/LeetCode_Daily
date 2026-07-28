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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> temp;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(level % 2 != 0){
                int i = 0, j = temp.size() - 1;
                while(i < j){
                    swap(temp[i]->val, temp[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        
        return root;
    }
};