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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            result.push_back(temp);
        }
        int levelNo = 0;
        for (auto level : result) {

            if (levelNo % 2 == 0) {      // Even level
                for (int i = 0; i < level.size(); i++) {

                    if (level[i] % 2 == 0)
                        return false;

                    if (i > 0 && level[i] <= level[i - 1])
                        return false;
                }
            }
            else {                   
                for (int i = 0; i < level.size(); i++) {
                    if (level[i] % 2 != 0)
                        return false;
                    if (i > 0 && level[i] >= level[i - 1])
                        return false;
                }
            }
            levelNo++;
        }

        return true;
    }
};