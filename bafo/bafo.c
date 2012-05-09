#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, i = 0, aa = 0, ba = 0, a = 0, b = 0, k = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		a = 0;
		b = 0;
		
		for(i=0;i<n;i++){
			scanf("%d %d", &aa, &ba);
			
			a += aa;
			b += ba;
		}
		
		printf("Teste %d\n", ++k);
		printf("%s\n\n", a>b?"Aldo":"Beto");
	}

	return 0;
}
