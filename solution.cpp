// 找规律就可以了，会发现结果在1-9之间循环出现，所以对9取余，然后注意余数为0的时候，替换成9，就可以了
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int res = num%9;
        if(res==0){
            return 9;
        }
        return res;
    }
};