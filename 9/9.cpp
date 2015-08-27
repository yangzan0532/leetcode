#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

class Solution {
	public:
	    bool isPalindrome(int x) {
			int a,b;
			int max_int =1000000000;
			if( x < 10 && x >= 0) return true;
			else if(x < 0) return false;

			while(x / max_int == 0){
				max_int /= 10;
			};
			do{
				a = x / max_int;
				b = x % 10;	
				x -= a * max_int;
				x /= 10;
				max_int /= 100;
			}while(a == b && max_int);

			if(!x && a == b)
				return true;
			else
				return false;
		}
};


int main(){
	int x;
	Solution s;
	while(1){
		cin >> x;
		cout << s.isPalindrome(x) << endl;
	}
	return 0;
}
