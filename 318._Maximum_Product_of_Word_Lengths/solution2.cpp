class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result =0;
        vector<pair<int, int> >wflag;
        for(int i=0; i < words.size(); ++i){
            int wlen = words[i].length();
            int letter = 0;
            for(int j=0; j< wlen; ++j){
                letter |= (1 << (words[i][j]-'a'));
            }
            wflag.push_back(make_pair(letter, wlen));
        }
        for(int i=0; i < wflag.size(); ++i){
            for(int j=i+1; j< wflag.size(); ++j){
                if((wflag[j].first & wflag[i].first) == 0){
                    int res = wflag[i].second * wflag[j].second;
                    result = res > result ? res : result; 
                }
            }
        }
        return result;
    }
};
