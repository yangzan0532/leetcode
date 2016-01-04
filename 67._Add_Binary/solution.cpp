// 大数加法的简单版本
class Solution {
public:
    string addBinary(string a, string b) {
        vector<char> res;
        int flag = 0;
        int a_len = a.length()-1;
        int b_len = b.length()-1;
        int ia,ib;
        int t_res;
        for(; a_len>=0 && b_len>=0; --a_len,--b_len){
            ia = a[a_len]=='1' ? 1:0;
            ib = b[b_len]=='1' ? 1:0;
            t_res = ia+ib+flag;
            flag = t_res > 1 ? 1:0;
            res.push_back((t_res % 2+48));
        }
        while(a_len >= 0){
            ia = a[a_len]=='1' ? 1:0;
            t_res = ia + flag;
            flag = t_res > 1 ? 1:0;
            res.push_back((t_res % 2+48));  
            --a_len;
        }
        while(b_len>= 0){
            ib = b[b_len]=='1' ? 1:0;
            t_res = ib+flag;
            flag = t_res > 1 ? 1:0;
            res.push_back((t_res % 2+48));
            --b_len;
        }
        if(flag){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        string s(res.begin(), res.end());
        return s;
    }
};
