#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, a = 0, r = 0, y = 0, p = 0, k = 0, u = 0;
	char s[401];
	
	while(1){
	
		scanf("%d", &n);
		
		if(!n)break;
		
		scanf("%s", s);
		
		p = 1;
		y = 0;
		r = 0;
		a = 0;
		u = s[y] == '-'?-1:1;

		while(s[y] != '\0'){
			switch(s[y]){
				case '-': case '+': 
					r += u * a;
				
					a = 0;
					p = 1;
					u = s[y]=='+'?1:-1;
				break;
				
				default: 
					a = a * p + (s[y] - 48);
					p *= 10;
				break;
			}
			
			y++;
		}
		
		r += u * a;
		
		printf("Teste %d\n%d\n", ++k, r);
	}

	return 0;
}
