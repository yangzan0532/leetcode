/*
 *
 *	用位运算来节约内存
 *
 * */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10){
            vector<string> ret;
            return ret;
        }
        unordered_map<int, int>res;
        unordered_map<int, int>::iterator iter;
        int char_2_int[200];
        char_2_int['A'] = 0;
        char_2_int['C'] = 1;
        char_2_int['G'] = 2;
        char_2_int['T'] = 3;
        set<string> ans;
        int key=0;
        for(int i=0; i<10; ++i){
            key <<= 2;
            key |= char_2_int[s[i]];
        }
        res[key]=1;
        
        for(int i=10; i<s.length(); ++i){
            key <<= 2;
            key |= char_2_int[s[i]];
            key &= 0xfffff;
            iter = res.find(key);
            if(iter != res.end()){
                iter->second += 1;
                ans.insert(s.substr(i-9, 10));
            }
            else{
                res[key]=1;
            }
        }
        vector<string> ret(ans.begin(), ans.end());
        return ret;
    }
};
