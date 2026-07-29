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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            bool foundX = false;
            bool foundY = false;

            for (int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if (curr->val == x) foundX = true;
                if (curr->val == y) foundY = true;

                if (curr->left && curr->right) {
                    int l = curr->left->val;
                    int r = curr->right->val;

                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (foundX && foundY) return true;
            if (foundX || foundY) return false;
        }

        return false;
    }
};