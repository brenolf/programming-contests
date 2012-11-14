#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1005];

inline int mov(int n){
	char at = str[n];

	if(at < 'n')
		return 'a' - at;
	else if(at > 'n')
		return 26 + 'a' - at;
	else
		return 13;
}

inline int same(int a, int b){
	return ((a <= 0 && b <= 0) || (a >= 0 || b >= 0));
}

inline int max(int a, int b){
	return a > b ? a : b;
}

inline int min(int a, int b){
	return a < b ? a : b;
}


int cadeado(int n){
	
	if(!n)
		return mov(n);
		
	int t = cadeado(n - 1), h = mov(n), r = same(t, h);
	
	t *= -1;
	h *= -1;
	
	if(r)
		return max(t, h);
	
	return t + h;
}

int main(){
	
	int i = 0;
	
	while(1){
		scanf("%s", str);
		getchar();
		
		if(!strcmp(str, "*"))
			break;
			
		printf("%d\n", cadeado(strlen(str) - 1));
	}

	return 0;
}
