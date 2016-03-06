/*=============================================================================
#     FileName: 12_Integer_to_Roman.cpp
#         Desc:  
#       Author: fluyy
#        Email: tulneer@gmail.com
#     HomePage: http://blog.fluyy.net
#      Version: 0.0.1
#   LastChange: 2016-03-06 22:22:03
#      History:

这道题没有什么难点，关键在于理清楚 罗马数字和阿拉伯数字之间的转换关系

这里贴一下维基百科上的罗马数字的介绍

https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97

1. 左减时不可跨越一个位值。比如，99不可以用IC（100 - 1）表示，而是用XCIX（[100 - 10] + [10 - 1]）表示。
  （等同于阿拉伯数字每位数字分别表示。）
2. 左减数字必须为一位，比如8写成VIII，而非IIX。

所以我的代码中将 4， 9， 40， 90 等直接打表就可以了

=============================================================================*/


#include<iostream>
#include<cstdio>
#include<string>

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
			string R[] = { "I", "IV", "V", "IX", "X" , "XL", "L", "XC" , "C", "CD", "D", "CM", "M"};
			int A[] ={1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
			string res = "";
			while(num){
				for(int i=12; i>=0 && num > 0; ){
					if(num >= A[i]){
						num -= A[i];
						res += R[i];
					}
					else{
						--i;
					}
				}
			}
			return res;
    }
};


int main(){

	int input;
	Solution s;
	while(true){
		cin >> input ;
		cout << s.intToRoman(input) << endl;
	}
	return 0;
}
