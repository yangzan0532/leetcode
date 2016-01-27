class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int flag=1;
        vector<int> res;
        for(int i=digits.size()-1; i>=0;  --i){
            digits[i]+=flag;
            if(digits[i] > 9){
                digits[i]%=10;
                flag = 1;
            }
            else{
                flag = 0;
            }
        }
        if(flag) res.push_back(1);
        for(int i=0; i<digits.size(); ++i){
            res.push_back(digits[i]);
        }
        return res;
    }
};
