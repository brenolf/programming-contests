#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, v = 0, q = 0, k = 0;
	
	while(1){
		scanf("%d", &v);
		
		if(!v)break;
		
		q = 0;
		
		printf("Teste %d\n", ++k);
		
		while(v>=50){
			q++;
			v-=50;
		}
		
		printf("%d ", q);
		
		q = 0;
		
		while(v>=10){
			q++;
			v-=10;
		}
		
		printf("%d ", q);
		
		q = 0;
		
		while(v>=5){
			q++;
			v-=5;
		}
		
		printf("%d %d\n\n", q, v);
	}

	return 0;
}
