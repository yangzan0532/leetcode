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
    int nums ;
    int countNodes(TreeNode* root) {
        return count(root);
    }
    int count(TreeNode *r){
        if(!r) return 0;
        if(r->right == NULL){
            if(r->left == NULL){
                return 1;
            }
            else{
                return 2;
            }
        }
        int h = height(r);
        int rh = height(r->right);
        if(h == rh+1){
            // 左边是满二叉树，右边是完全二叉树
            return  ((2<< rh ) + count(r->right)); 
            // (2 << (h -1)) - 1 是左边满二叉树的节点数 ， 
            // 再加上根节点 最后左边部分的节点数为 (2 << (h - 1)) -1 +1 
            // 结果化简等于 2 << (h-1) 
            // 也等于 2 << rh 
        }
        else {
            // 左边是完全二叉树，右边是满二叉树
            return ((2<<rh)  + count(r->left));
        }
    }
    
    int height(TreeNode *r){
        int ret = 0;
        while(r){
            ++ret;
            r=r->left;
        }
        return ret - 1;
    }
};
