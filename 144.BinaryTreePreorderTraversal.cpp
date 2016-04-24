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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        lmr(res, root);
        return res;
    }
    void lmr(vector<int>& res, TreeNode *root){
        if(root){
            res.push_back(root->val);
            lmr(res, root->left);
            lmr(res, root->right);
        }
    }
};
