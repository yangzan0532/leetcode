// 这种算法比较基础，可以用位运算加速。
// 1。单词中字母存在，则对应位置1。并用一个int保存下来。
// 2. 比较时将两个单词对应的的标记进行 & 运算，如果有相同的字母，则结果不为0.
// 相信算法见solution2
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result =0;
        for(int i=0; i < words.size(); ++i){
            int t_map[26] = {0};
            int ilen = words[i].length();
            int jlen = 0;
            for(int ii=0; ii< ilen; ++ii){
                t_map[words[i][ii]-'a']=1;
            }
            for(int j=i+1; j< words.size(); ++j){
                if(words[j].length() <= jlen ) continue;
                if(has_same_letter(t_map, words[j])){
                    continue;
                }
                else{
                    jlen = words[j].length();
                    int res = ilen * jlen;
                    result = result > res ? result : res;
                }
            }
        }
        return result;
    }
    bool has_same_letter(int *t_map, const string &b){
        for(int i=0; i<b.length(); ++i){
            if(t_map[b[i]-'a'] == 1 ){
                return true;
            }
        }
        return false;
    }
};
