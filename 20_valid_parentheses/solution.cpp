#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		bool isValid(string s){
			char stack[200]={0};
			int top=0;
			for(int i=0; i<s.size(); i++)
			{
				if((s[i] == '(' && stack[top] == ')') || (s[i] == ')' && stack[top] == '('))
				{
					top--;
				}
				else if((s[i] == '[' && stack[top] == ']') || (s[i] == ']' && stack[top] == '['))
				{
					top--;
				}
				else if((s[i] == '{' && stack[top] == '}') || (s[i] == '}' && stack[top] == '{'))
				{
					top--;
				}
				else{
					stack[++top] = s[i];
				}	
			}
			cout <<"top:" << top << endl;
			if(top)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
};

int main()
{
	string s;
	Solution solution;
	while(1)
	{
		cin >> s;
		cout << solution.isValid(s) << endl;
	}
	return 0;
}
