class Solution {
public:
    bool isAdditiveNumber(string& num) {
        string res;
        for(int i=1; i<num.size(); ++i){
            if(num[0] == '0' && i>1) break;
            string num1 = num.substr(0, i);
            for(int j=1; j+i<num.size(); ++j){
                if(num[i] == '0' && j>1) break;
                string num2 = num.substr(i, j);
                int pos = i+j;
                //cout << i <<" "<<j << endl;
                while(1){
                    add(num1, num2, res);
                    //cout << "R:"<< num1 << " "<<num2 <<" " << res << endl;
                    int p=0;
                    int equal = true;
                    for(p=0; p<res.length() && p+pos<num.length(); ++p){
                        if(res[p] != num[p+pos]){
                            equal = false;
                            break;
                        }
                    }
                    if(equal){
                        if(p+pos == num.length()){
                            return true;
                        }
                        else{
                            pos += p;
                            num1 = num2;
                            num2 = res;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return false;
    }
private:
    void add(const string& a, const string& b, string &ret){
        int flag = 0;
        int al = a.length()-1;
        int bl = b.length()-1;
        vector<char> ans;
        while(al >=0  && bl>=0){
            int res = a[al]+b[bl]-'0'-'0'+flag;
            if(res > 9){
                flag = 1;
                res -= 10;
            }
            else
            {
                flag = 0;
            }
            ans.push_back(res+'0');
            --al;
            --bl;
        }
        
        while(al >= 0){
            int res = a[al]-'0'+flag;
            if(res > 9){
                flag = 1;
                res -= 10;
            }
            else flag=0;
            ans.push_back(res+'0');
            --al;
        }
        while(bl >= 0){
            int res = b[bl]-'0'+flag;
            if(res > 9){
                flag = 1;
                res -= 10;
            }else flag=0;
            ans.push_back(res+'0');
            --bl;
        }
        if(flag) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        ret.assign(ans.begin(), ans.end());
    }
};
