// 二分搜索，快速解决，注意l+m会溢出，导致超时错误 
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m=n ;
        if(n<2) return n;
        while(l <= r){
            m = l + (r - l) / 2;;
            if(isBadVersion(m)){
                r = m;
                if(!isBadVersion(m-1)){
                    return m;
                }
            }
            else{
                l = m+1;
            }
        }
        return m;
    }
};
