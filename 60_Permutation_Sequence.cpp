/*
 * 这道题显然不能暴力枚举所有排列去求解，那样一定会超时
 * 我们观察给出的案例:
 * 123
 * 132
 *
 * 213
 * 231
 *
 * 312
 * 321
 * 
 * 1. n个数的全排列为n！个，n-1个数的全排列为(n－1)!.也就是说，给定一个n
 * 以1开头的数有(n-1)!个，
 * 以2开头的数也有(n-1)!个，依次类推,我们定义 count(n)表示n的阶乘的数目
 * 我们将 k/count(n-1)我们就可以确认开头的数字是多少。
 * 接下来这个问题就分解成了n－1个数的阶乘问题，用递归很容易解决
 * */

class Solution {
public:
    int cnt[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    vector<int> tmp;
    vector<char>res;
    string getPermutation(int n, int k) {
        res.clear();
        mk_seq(n);
		find(n, k-1);
		string t(res.begin(), res.end());
		return t;
    }
    
    int find(int n, int k){
    	if(tmp.size() <= 0) return 0;
    	int ret = k/cnt[n-1];
    	if(ret < tmp.size()){
    		res.push_back(tmp[ret]+48);
    		tmp.erase(tmp.begin()+ret);
    		find(n-1, k-cnt[n-1]*ret);
    	}
    	return 0;
    }
    
    int mk_seq(int n){
	    tmp.clear();
	    for(int i=0; i<n; ++i){
		    tmp.push_back(i+1);
	    }
	    return 0;
    }
};
