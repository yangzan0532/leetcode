/*
 * 树的遍历，水题
 *
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
	vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
		string s;
		if(root){
			s.append(to_string(root->val));
			if(root->left == NULL && root->right == NULL){
				result.push_back(s);
			}
			if(root->left){
				dlr(root->left, s);
			}
			if(root->right){
				dlr(root->right, s);
			}
		}
		return result;
    }

	void dlr(TreeNode* root, string s){
		s.append("->");
		s.append(to_string(root->val));

		if(root->left == NULL && root->right == NULL){
			result.push_back(s);
		}
		if(root->left){
			dlr(root->left, s);
		}
		if(root->right){
			dlr(root->right, s);
		}	
	}
};
