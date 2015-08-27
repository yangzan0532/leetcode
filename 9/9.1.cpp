#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

class Solution {
	public:
	    bool isPalindrome(int x) {
			long long tx =0L;
			long long lx = (long long)x;
			if( x < 10 && x >= 0) return true;
			else if(x < 0) return false;
			do{
				tx = tx * 10L +  lx % 10;
				lx = lx / 10;
			}while(lx != 0L);
			return (tx == (long long)x);
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
