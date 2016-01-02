/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // 下面是递归解法
class Solution {
public:
    vector<int>s;
    vector<int>rs;
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        s.clear();
        rs.clear();
        visit(root->left);
        visit_r(root->right);
        if(s.size() % 2 == 0){
            return false;
        }
        if(s.size() == rs.size()){
            for(int i=0; i<s.size(); ++i){
                if(s[i] == rs[i]){
                    continue;
                }
                else{
                    return false;
                }
            }   
        }
        else{ 
            return false;
        }
        return true;
    }
    int visit(TreeNode *root){
        if(root == NULL){
            s.push_back(-1);
        }else{
            s.push_back(root->val);
            visit(root->left);
            visit(root->right);
        }
        return 0;
    }
    int visit_r(TreeNode *root){
        if(root == NULL){
            rs.push_back(-1);    
        }else{
            rs.push_back(root->val);
            visit_r(root->right);
            visit_r(root->left);
        }
        return 0;
    }
};
