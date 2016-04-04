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
    int target;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        target = sum;
        res.clear();
        vector<int> tmp;
        visit(root, tmp, 0);
        return res;
    }
    
    void visit(TreeNode* root, vector<int> &tmp, int currentVal){
        if(root){
            int newVal = currentVal + root->val;
            tmp.push_back(root->val);
            //cout << "left:" << root->left << " right:" << root->right << endl;
            //cout << "cur:" << newVal << " taget:" << target << endl;
            if(!root->left && !root->right){
                if(newVal == target){
                    res.push_back(tmp);
                }
            }
            if(root->left)  visit(root->left, tmp, newVal);
            if(root->right) visit(root->right, tmp, newVal);
            tmp.pop_back();
            
        }
    }
};
