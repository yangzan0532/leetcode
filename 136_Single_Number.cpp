// 根据位运算 xor 的运算特点， 相同的树异或为0 ， 则 a1 ^ a1 ^ a2 ^ a2 ^ ... ^ aj ^ ... ^ an ^ an = aj
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(size_t  i =0; i<nums.size(); ++i){
            res ^= nums[i];
        }
        return res;
    }
};
