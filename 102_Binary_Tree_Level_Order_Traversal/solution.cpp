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
    vector<vector<int> >res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        res.clear();
        levelvisit(root, 0);
        return res;
    }
    
    void levelvisit(TreeNode *root, int level){
        if(root == NULL){
            return ;    
        }
        if(level >= res.size() ){
            vector<int> tmp;
            res.push_back(tmp);
        }
        res[level].push_back(root->val);
        
        levelvisit(root->left, level+1);
        levelvisit(root->right, level +1);
    }
};
