#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, c = 0, r = 0;
	char b[32];
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		c = 0;
		r = 0;
		
		while(n){
			r += n%2;
			b[c++] = (n%2) + 48;
			n/=2;
		}
		
		b[c] = '\0';
		
		printf("The parity of ");
		
		for(i=c-1;i>=0;i--)printf("%c", b[i]);
		
		printf(" is %d (mod 2).\n", r);
	}

	return 0;
}
