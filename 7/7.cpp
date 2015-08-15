#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        //	int max_n = 2147483647; -2147483648
		int max_n = 214748364;
		int res = 0;
		while(x){
			res = res*10+(x%10);
			x/=10;
			//cout << res << " : "<< x <<" "<<x%10<<endl;
			if((abs(res) > max_n && x!=0)||(abs(res) == max_n && x > 7)){
                //cout << "break" << endl;
                res = 0;
                break;
			}
		}
		return res;
    }
};

int main(){
	Solution s;
	int in;
	while(1){
		cin >> in ;
		cout << s.reverse(in) << endl;
	}
	return 0;
}
