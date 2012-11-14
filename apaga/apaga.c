#include <stdio.h>
#define MAX 100001

char stack[MAX];
int P = 0, N = 0;

void popUntil(char c){
	if(!P)
		return;
	
	int i = 0;
	
	for(i = P - 1; i >= 0 && N; i--){
		if(stack[i] >= c)
			break;
		N--;
	}
	
	P = i + 1;
}

void push(char c){
	stack[P++] = c;
}

int main(){
	
	char str[MAX];
	int d = 0, i = 0, n = 0;

	while(1){
		scanf("%d %d", &d, &n);
		
		if(!d && !n)
			break;
		
		scanf("%s", str);
		
		P = 0;
		N = n;
		
		for(i = 0; i < d; i++){
			popUntil(str[i]);
			push(str[i]);
		}
		
		for(i = 0; i < d - n; i++)
			printf("%c", stack[i]);
			
		printf("\n");
	}

	return 0;
}
