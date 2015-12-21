class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m_s[41500]={0};
        int m_t[41500]={0};
        int s_len = init(s.c_str(), m_s);
        int t_len = init(t.c_str(), m_t);
        for(int i=0; i<s_len; ++i){
            if(m_s[i] != m_t[i]){
                return false;
            }
        }
        return true;
    }
    int init(const char *s, int *strmap){
        int t_map[256]={0};
        int len = 1;
        for(int i=0; s[i]!='\0'; ++i){
            if(t_map[s[i]] == 0){
                t_map[s[i]] = len;
                ++len;
            }
            strmap[len] = t_map[s[i]];
            ++len;
        }
        return len;
    }
};
