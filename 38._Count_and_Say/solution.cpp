// 简单模拟题
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        string tmp_res="";
        for(int i=1; i<n; ++i){ // n 次循环
            const char *str = res.c_str();
            char num;
            int count=0;
            for(int j=0; str[j]!='\0'; ++j){
                if(num != str[j]){
                    if(count != 0){
                        tmp_res += to_string(count);
                        tmp_res += num;
                    }
                    count = 1;
                    num = str[j];
                }
                else{
                    ++count;
                }
            }
            if(count != 0){
                tmp_res += to_string(count);
                tmp_res += num;
            }
            res = tmp_res;
            tmp_res = "";
        }
        return res;
    }
};
