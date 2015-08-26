#include<stdio.h>
#include<string.h>

int myAtoi(char* str) {
	long long  res = 0;
	long long flag = 1;
	int p = 0;
	const int INTMAX = 2147483647;
	const int INTMIN = -2147483648;
	const int INT_BASE = 214748364;
	while(str[p] != 0 && str[p] == ' '){
		p++;	
	}

	if(str[p] == '+'){
		flag = 1L;	
		++p;
	}
	else if(str[p] == '-'){
		flag = -1L;
		++p;
	}
	while(str[p] != 0){
		if(str[p] >= '0' && str[p] <= '9')
		{
			res = res * 10L + (long long)(str[p]-'0');
		}
		else{
			return (int)(res * flag);
		}
		if( flag * res >= INTMAX){				
			return INTMAX;	
		}

		if( flag * res <= INTMIN){
			return INTMIN;
		}
		++p;
	}
	return (int)(res * flag);	
}

int main(){
	char str[100];
	while(1){
		scanf("%s", str);
		printf("%d\n", myAtoi(str));		
	}
	return 0;
}
