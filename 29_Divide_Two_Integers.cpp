/*
 *
 * 用分治的思想解决
 *
 * */
#include<iostream>
#include<string>


using namespace std;
class Solution {
public:
	int res;
	long long  dividend;
    int divide(int idividend, int divisor) {
		int sign = 1;
		res = 0;
        if(!divisor || (idividend==INT_MIN && divisor==-1))   return INT_MAX;
		if(idividend == INT_MIN && divisor == 1) return INT_MIN;
		if((idividend<0 && divisor >0) || ( idividend >0 && divisor < 0)) sign = -1;
		dividend = myabs64(idividend);
		cout << dividend << endl;
		div( myabs64(divisor), 1);
		return res * sign;
    }
	long long myabs64(long long a){
		if(a < 0) return -1L * a;
		return a;
	}
	void div(long long divisor, int times){
		long long  td = divisor + divisor;
		if(td <= dividend){
			div(td, times+times);
		}
		if(divisor <= dividend){
			dividend -= divisor;
			res += times;
		}
	}
};

int main(){

	Solution s;
	int a, b;
	while(1){
		cin >> a >> b ;
		cout << s.divide(a, b) << endl;
	}
	return 0;
}
