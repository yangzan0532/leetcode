/*=============================================================================
#     FileName: 13_Roman_to_Integer.cpp
#         Desc:  
#       Author: fluyy
#        Email: tulneer@gmail.com
#     HomePage: http://blog.fluyy.net
#      Version: 0.0.1
#   LastChange: 2016-03-06 23:18:54
#      History:

这里和inter 2 Roman一样，暴力做一遍就可以了

=============================================================================*/


#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		int res = 0;
		for(size_t i=0; i<s.length(); ++i){
			switch(s[i])
			{
				case 'I':
				{
					if(s[i+1] == 'V')
					{
						res += 4;
						++i;
					}
					else if(s[i+1] == 'X')
					{
						res += 9;
						++i;
					}
					else{
						res += 1;
					}
					break;
				}
				case 'V':
				{
					res += 5;
					break;
				}
				case 'X':
				{	
					if(s[i+1] == 'L'){
						res += 40;
						++i;
					}
					else if(s[i+1] == 'C'){
						res += 90;
						++i;
					}
					else{
						res += 10;
					}
					break; 
				}
				case 'L':
				{
					res += 50;
					break;
				}
				case 'C':
				{	
					if(s[i+1] == 'D'){
						res += 400;
						++i;
					}
					else if(s[i+1] == 'M')
					{
						res += 900;
						++i;
					}
					else{
						res += 100;
					}
					break;
				}
				case 'D':
				{
					res += 500;
					break; 
				}
				case 'M':
				{
					res += 1000;
					break;
				}
			}
		}
		return res;
    }
};

int main(){
	string input; 
	Solution  s;
	while(1){
		cin >> input ;
		cout << s.romanToInt(input) << endl;
	}
	return 0;
}
