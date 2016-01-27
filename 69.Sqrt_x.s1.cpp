class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        int m=0;
        if(x == 1) return 1;
        while(l<=r){
            m = l + ((r - l) / 2); // l+r 可能会溢出 
            int res = x/m;
            if(res == m){
                return m;
            }
            else if(res < m){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return r;
    }
};
