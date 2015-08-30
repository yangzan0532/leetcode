/*=============================================================================
#     FileName: ZigZag_Conversion.cpp
#         Desc:  
#       Author: fluyy
#        Email: tulneer@gmail.com
#     HomePage: http://blog.fluyy.net
#      Version: 0.0.1
#   LastChange: 2015-08-29 21:25:54
#      History:
=============================================================================*/
//2n-2-i*2, i*2;
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			if( numRows <= 1) return s;
			string res = s;
			int iter = 0;
			for(int i=0; i<numRows; ++i){
				int pos = i;		
				int delta2 = i*2;
				int delta = 2 * numRows - 2 - delta2;
				res[iter++] = s[pos];
				do{
					pos += delta;
					if(delta){
						if(pos < s.length()){
							res[iter++] = s[pos];
						}
						else{
							break;
						}
					}
					if(delta2){
						pos += delta2;
						if(pos < s.length()){
							res[iter++] = s[pos];
						}
						else{
							break;
						}
					}	
				}while(true);
			}
			return res;
		}
};

int main(){
	int row;
	string ss;
	Solution s;
	while(1){
		cin >> ss >> row;
		cout << s.convert(ss, row) << endl;
	}
	return 0;
}

