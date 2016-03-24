
// 遍历树的时候，标记树的深度

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
    vector< vector<int> >ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ans.clear();
        mlr(root, 0);  
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void mlr(TreeNode* root, int level){
        if(!root) return ;
        if(level >= ans.size()){
            vector<int> t;
            ans.push_back(t);
        }
        ans[level].push_back(root->val);
        mlr(root->left, level+1);
        mlr(root->right, level+1);
    }
};
