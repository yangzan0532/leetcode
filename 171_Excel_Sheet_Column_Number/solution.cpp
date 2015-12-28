class Solution {
public:
    int titleToNumber(string s) {
        const char *ss = s.c_str();
        int res = 0;
        for(int i=0; ss[i]!='\0'; ++i){
            res = res*26+(ss[i]-'A'+1);
        }
        return res;
    }
};
