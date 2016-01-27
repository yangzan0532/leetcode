//
// 这道题给我们一个数组，让我们返回一个新数组，使得新数组每一个位置上的数是其他位置上数的乘积
// 要求：
// 1. 不能使用出发，
// 2. 常数空间
// 假设能够使用除法， 则用乘积除以对应位置上的数即可。
// 借用存放结果的返回数组，这样维护两个数组，一个是左边的乘积和，一个是右边数的乘积和。
// ［1，2，3，4］
//  res ＝ ［24，24，12，4］
//  nums＝ ［ 1， 2， 6，26］
//  结果res ＝ [24, 12, 8, 6] 
//  res[i] = res[i+1] * num[i-1]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> res(n, 0);
        res[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i){
            res[i] = nums[i] * res[i+1];
        }
        for(int i=1; i<n; i++){
            nums[i] *= nums[i-1];
        }
        res[0]=res[1];
        for(int i=1, e=n-1; i<e; ++i){
            res[i] = res[i+1] * nums[i-1];
        }
        res[n-1] = nums[n-2];
        return res;
    }
};
