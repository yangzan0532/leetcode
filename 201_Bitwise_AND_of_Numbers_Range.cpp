
// m != n 时，最后一位一定有0， and操作之后，这一位一定是0.
// 当m等于n，说明m与n对应的位都相同。and操作之后，还是不变
// 所以不断右移m,n，使得m＝n，记录右移的次数，即可知道m,n之间有多少位是相同的

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int offset = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            ++offset;
        }
        return n<<offset;
    }
};
