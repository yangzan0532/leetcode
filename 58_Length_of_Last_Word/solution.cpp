class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_p=0,e_p=0;
        int curr=0;
        int length = s.length();
        while(curr < length){
            if(s[curr]==' ' && s[curr+1] != '\0' && s[curr+1] != ' '){
                s_p=curr+1;
            }
            else if(s[curr]!=' '){
                e_p=curr+1;
            }
            curr++;   
        }
        //cout << s_p << " " << e_p << endl;
        if(s_p < e_p ){
            return e_p -s_p;
        }
        return 0;
    }
};
