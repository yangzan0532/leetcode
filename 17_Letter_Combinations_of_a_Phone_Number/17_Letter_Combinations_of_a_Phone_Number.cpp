#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char *ss[] = { "", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char *res[50000];
int nums[100];
int g_len;
int g_count = 0;
int push(char *);
int dfs(int cur, char *t_res){
	int i = 0;
	int str_len = 0;
	int iter = 0;
	if(cur == g_len){
		t_res[cur] = '\0';
		push(t_res);
		return 0;
	}
	iter = nums[cur];
	str_len= strlen(ss[iter]);
	for(i=0; i< str_len; ++i){
		t_res[cur] = ss[iter][i];	
		dfs(cur+1, t_res);
	}
	return 0;
}

int push(char *src){
	res[g_count] = (char *)malloc(strlen(src)+1);
	strcpy(res[g_count], src);
	++g_count;
	return 0;
}

char** letterCombinations(char* digits, int* returnSize) {
	if(digits == NULL || strlen(digits) == 0) return NULL;
	int i=0;
	char t_res[100];
	g_len = strlen(digits);
	g_count = 0;
	for(i=0; i< g_len; ++i){
		nums[i] = digits[i] - '0';
	}
	dfs(0, t_res);
	*returnSize = g_count;
	return res;
}

int main(){
	int return_len;
	char aa[1000];
	while(1){
		scanf("%s", aa);
		char ** t = letterCombinations(aa, &return_len);
		for(int i=0; i< return_len; ++i){
			printf("- %s\n", t[i]);
		}
	}
	return 0;
}
