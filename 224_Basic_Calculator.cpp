// 比较简单的算法，用了递归去解决。
class Solution {
public:
    char ss[20];
    int calculate(string s) {
        return calc(s.c_str(), s.length());
    }
    int getSubExpression(const char *str){
        int beg_count = 1;
        int end_ptr = 0;
        for(int i=0; str[i] != '\0'; ++i){
            if(str[i] == ')'){
                end_ptr++;
                if(end_ptr == beg_count)  return i+1;
            }
            else if(str[i] == '('){
                beg_count++ ;
            }
        }
        return 0;
    }

    void get_num(const char *s){
        int j = 0;
        for(; s[j] != '\0' && s[j] <= '9' && s[j] >= '0' ; ++j){
            ss[j] = s[j];
        }
        ss[j] = '\0';
    }

	// 计算表达式的递归
    int calc(const char *s, int len){
        int ans = 0;
        int flag = 1;
        for(size_t i=0; i<len; ++i){
            if(s[i] <= '9' && s[i] >= '0' ){
                get_num(s+i);
                i += (strlen(ss)-1);
                ans += (flag * atoi(ss));
                //cout << ans << "  " << s << "  " << s[i] << "  " << i << endl;
                continue;
            }
            else if(s[i] == '-'){
                flag = -1;
            }
            else if(s[i] == '+'){
                flag = 1;
            }
            else if(s[i] == '('){
                //cout << "enter:" << ans << endl;
				//获取子表达式 1+2+3+(4+5-(6+7)-9) , 括弧里的就是子表达式     
                int sub_len = getSubExpression(s+i+1);
                int res = calc(s+i+1, sub_len);
                ans += (flag * res);
                //cout << "exit:" << ans  << "= (?)+" << flag << "*" << res  << "sl:" << sub_len << " " << s[i+sub_len] << endl;
                i += sub_len;
            }
        }
        return ans;
    }
};
