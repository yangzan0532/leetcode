//
// 题目要求不能使用循环和递归。
// 那么，我这里先开三次方，然后再求幂，比较结果是否相同
//
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double result = (int)(0.5 + log(n)/log(3));
        return (pow(3, result) == n);
    }
};
