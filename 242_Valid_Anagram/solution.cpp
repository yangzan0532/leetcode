class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int m_s[256]={0};
        int m_t[256]={0};
        const char *c_s = s.c_str();
        const char *c_t = t.c_str();
        for(int i=0; c_s[i]!='\0'; ++i){
            m_s[c_s[i]]++;
        }
        for(int i=0; c_t[i]!='\0'; ++i){
            m_t[c_t[i]]++;
        }
        for(int i='a'; i<='z'; ++i){
            if(m_t[i] != m_s[i]){
                return false;
            }
        }
        return true;
    }
};
