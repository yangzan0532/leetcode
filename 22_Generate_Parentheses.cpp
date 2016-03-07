/*=============================================================================
#     FileName: 22_Generate_Parentheses.cpp
#         Desc:  
#       Author: fluyy
#        Email: tulneer@gmail.com
#     HomePage: http://blog.fluyy.net
#      Version: 0.0.1
#   LastChange: 2016-03-07 23:58:03
#      History:

这道题比较简单，关键在思路的转变

我们把(和)分别看出二叉树的左孩子和右孩子，然后我们遍历二叉树，保证左边的节点数大于等于右边的节点数，进行搜索就可以了

=============================================================================*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	int n;
	vector<string> ans;
    vector<string> generateParenthesis(int n){
        this->n = n;
		ans.clear();
		string ls = "(";
		search(1, 0, ls);
		return ans;
    }
	
	void search(int lc, int rc, string &res){
		if(lc == n && rc == n){
			ans.push_back(res);
		}
		else if(lc >= rc){
			if(rc < n){
				string rs = res+")";
				search(lc,  rc+1,  rs);
			}
			if(lc < n){
				string ls = res+"(";
				search(lc+1, rc,   ls);
			}
		}
	}
};


int main(){
	Solution s;
	int n;
	while(1){
		cin >> n;
		s.generateParenthesis(n);
	}
	return 0;
}
