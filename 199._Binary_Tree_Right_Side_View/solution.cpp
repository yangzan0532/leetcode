/* 题意：假设你站在一棵二叉树的右边，然后将你能看到的节点从上到下的顺序记录下来。
 * 树的遍历，优先遍历右子树，如果发现进入新的一层，且该层是第一次遍历，则加入结果，并标记为
 * 已经遍历
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<int> visit;
        viewRight(root, res, visit, 1);
        return res;
    }
    
    void viewRight(TreeNode* root, vector<int> &out, vector<int>& visit,int level){
        if(root == NULL){
            return;
        }
        else if(level > out.size()){
            out.push_back(root->val);
            visit.push_back(level);
        }
        viewRight(root->right, out, visit, level+1);
        viewRight(root->left, out, visit, level+1);
    }
};
