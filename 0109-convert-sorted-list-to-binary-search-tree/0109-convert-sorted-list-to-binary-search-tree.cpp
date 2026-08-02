/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode* head, ListNode* l, ListNode* r){
        if(l == r) return NULL;
        ListNode* fast = l;
        ListNode* slow = l;
        while(fast != r && fast->next != r){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        TreeNode* root = new TreeNode(mid->val);
        root->left = solve(head,l,mid);
        root->right = solve(head, mid->next, r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head,head,NULL);
    }
};