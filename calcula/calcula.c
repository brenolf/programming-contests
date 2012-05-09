#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, a = 0, r = 0, k = 0;
	
	while(1){
	
		scanf("%d", &n);
		
		if(!n)break;
		
		r = 0;
		
		for(i=0;i<n;i++){
			scanf("%d", &a);
			r += a;
		}
		
		printf("Teste %d\n%d\n", ++k, r);
	}

	return 0;
}
