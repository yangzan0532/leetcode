
/*
 *判断一个数是不是2，3，5的倍数。,最直观的就是直接一个一个分解了
 * */
class Solution {
public:
    bool isUgly(int num) {
        while(num!=0 && num%2==0){
            num/=2;
        }
        while(num!=0 && num%3==0){
            num/=3;
        }
        while(num!=0 && num%5==0){
            num/=5;
        }
        if(num==1){
            return true;
        }
        else{
            return false;
        }
    }
};
