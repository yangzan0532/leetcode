class Solution {
public:
    string convertToTitle(int n) {
        vector<char>ss;
        string res;
        while(n>0){
            ss.push_back((n-1)%26+'A');
            n=(n-1)/26;
        }
        return res.assign(ss.rbegin(), ss.rend());
    }
};
