#include<stdio.h>
#include<string.h>

int min(int a, int b){
	return a < b ? a : b;
}
char *longestPalindrome(char *s){
	const int MAX_LEN = 2048;
	char ns[MAX_LEN];
	int p[MAX_LEN]; // = {0};
	int iter = 0;
	int pos = -1;
	int id = 0;
	int mx = 0;
	int res = 1;
	int res_id = 0;
	int start ,end;

	ns[iter++] = 1;
	memset(p, 0, sizeof(p));
	//处理字符串成新的格式
	do{
		ns[iter++] = 2 ;
		ns[iter++] = s[++pos];
	}while(s[pos] != '\0');
	
	//寻找最长回文串
	for(iter = 0; ns[iter] != 0; ++iter)
	{
		if(mx > iter){
			p[iter] = min(p[2*id-iter], mx - iter);
		}
		else{
			p[iter] = 1;
		}
		while(ns[iter + p[iter]] == ns[iter - p[iter]])  p[iter]++;
		if(p[iter] + iter > mx){
			mx = iter + p[iter];
			id = iter;
		}	
		if( res < p[iter] ){
		   	res = p[iter];
			res_id = id;
		} 
	}
	if(res_id % 2){ //偶数串
		start = res_id/2 - 1 - ((res-1)/2 - 1);
		end = start + res -1;
	}
	else{ //奇数串
		start = res_id/2 - 1 - (res-1)/2;
		end = start + res - 1;
	}
	s[end] = 0;
	return s + start;
}

int main(){
	char str[3000];
	char* s;
	while(1){
		scanf("%s", str);
		s = longestPalindrome(str);
		printf("%s\n",s);
	}
	return 0;
}
