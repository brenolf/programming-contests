#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, i = 0, a = 0, r = 1, k = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		r = 0;
		
		for(i=1;i<=n;i++){
			scanf("%d", &a);
			
			if(a == i)r = a;
		}
		
		printf("Teste %d\n%d\n\n", ++k, r);
	}

	return 0;
}
