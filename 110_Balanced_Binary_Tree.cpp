/*
 *  这道题又是一道很明显的递归解法，只要保证每棵子树的左右儿子深度相差不超过1就可以了
 * */
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
    bool flag;
    bool isBalanced(TreeNode* root) {
        flag = true;
        getLength(root);
        return flag;
    }
    
    int getLength(TreeNode *root){
        if(!root) return 0;
        int llen = getLength(root->left);
        int rlen = getLength(root->right);
        //cout << "l:" << llen << "  r:" << rlen << endl;
        if(llen > rlen){
            if(llen - rlen > 1) flag = false;
            return llen+1;
        }
        else{
            if(rlen - llen > 1) flag = false;
            return rlen+1;
        }
    }
};
