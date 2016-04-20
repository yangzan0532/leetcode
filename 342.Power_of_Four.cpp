class Solution {
public:
    bool isPowerOfFour(int num) {
        if(!num)  return false;
        while(num){
            if(num == 4 || num == 1) return true;
            if(num % 4) return false;
            if(num < 16) return false;
            num >>= 2;
        }
        return true;
    }
};
