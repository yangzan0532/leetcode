// 递归的解法通俗，简单
// 需要注意负数转化为为正数而导致的溢出问题。看到一种精妙的方法，
// 就是先求res = pow(x, (n-1)); 
// res = res * x;


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 ) return 1;
        if(n < 0) return 1.0/(my_pow(x,-(n+1))*x);
        else return my_pow(x, n);
    }
    double my_pow(double x, int n){
        double res = 1.0;
        double base = x;
        while(n){
            if(n&0x1){
                res *= base;
            }
            n >>= 1;
            base *= base;
        }
        return res;  
    }
};

// 递归解法
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 ) return 1;
        if(n < 0)   return 1.0/(myPow(x,-(n+1))*x);
        else{
            double res = myPow(x, n>>1);
            return res*res*((n&0x1)?x:1);
        }
    }
}
