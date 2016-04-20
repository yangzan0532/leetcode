/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        visit(0, root);
        return ans;
    }
    
    void visit(int ret, TreeNode *root){
        if(!root) return ;
        int tv = ret * 10 + root->val;
        if(!root->left && !root->right){
            ans += tv;
            return ;
        }
        visit(tv, root->left);
        visit(tv, root->right);
    }
};
