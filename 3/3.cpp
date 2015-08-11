#include<iostream>
#include<string>


using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			const int MAX_N = 129;
			int vis[MAX_N]={0};
			const char *str = s.c_str();
			int res = 0;
			int t_res = 0;
			int loop = 1;
			for(int i=0; i< s.size(); i++){
				char c = str[i];
				if(vis[c] == loop){ //表示这个字符访问过，
					i = vis[c]-1;
					res = res > t_res ? res : t_res;
					t_res = 0;
					loop++;
				}
				else{
					vis[c] = loop;
					t_res++;
				}
			}
			res = res > t_res ? res : t_res;
			return res;
		}
};

int main(){
	string str;
	Solution s;
	cin >> str;
	cout << s.lengthOfLongestSubstring(str);
	return 0;
}
