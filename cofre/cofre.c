#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, j = 0, z = 0, d = 0, k = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		printf("Teste %d\n", ++k);
		
		d = 0;
		
		for(i=0;i<n;i++){
			scanf("%d %d", &j, &z);
			
			d += j - z;
			
			printf("%d\n", d);
		}
		
		printf("\n");
	}

	return 0;
}
