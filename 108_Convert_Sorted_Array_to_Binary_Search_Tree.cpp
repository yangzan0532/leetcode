/*
 *  这道题是special judge ，害的我不知道怎么改代码，一提交就AC了
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
    
    TreeNode* build(vector<int>&nums, int beg, int end){
        if(beg > end) return NULL;
        int iter = (beg + end) >> 1;
        if(iter >= nums.size()) return NULL;
        TreeNode *ptr = new TreeNode(nums[iter]);
        ptr->left = build(nums, beg, iter-1);
        ptr->right = build(nums, iter+1, end);
        return ptr;
    }
};
