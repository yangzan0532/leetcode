class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int pattern_map[256]={0};
        int tot=1;
        int p_array[10000];
        int s_array[10000];
        int pattern_len = 0;
        const char *p = pattern.c_str();
        for(int i=0; p[i]!='\0'; ++i){
            if(pattern_map[p[i]] == 0){
                pattern_map[p[i]] = tot;
                ++tot;
            }
            p_array[pattern_len] = pattern_map[p[i]];
            ++pattern_len;
        }
        const char *s = str.c_str();
        char tmp[256];
        map<string, int>s_map;
        tot=1;
        int j=0,i=0;
        int word_num=0;
        while(1){
            if(s[i] == ' ' || s[i] == '\0'){
                tmp[j]='\0';
                if(s_map.insert(make_pair(tmp, tot)).second){
                    s_array[word_num] = tot;
                    ++tot;
                }
                else{
                    s_array[word_num] = s_map[tmp];
                }
                ++word_num;
                j=0;
                if(s[i] == '\0') break;
            }
            else{
                tmp[j++] = s[i];
            }
            ++i;
        }
        if(pattern_len != word_num) return false;
        for(int i=0; i<pattern_len; ++i){
            if(s_array[i] != p_array[i]){
                return false;
            }
            
        }
        return true;
    }
};
