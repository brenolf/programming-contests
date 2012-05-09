#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, i = 0, g1 = 0, g2 = 0, ac = 0, r = 0, aux = 0, k = 0, INI = 0, END = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
		
		ac = 0;
		r = 0;
		aux = 0;
		INI = 0;
		END = 0;
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &g1, &g2);
			
			ac += g1 - g2;
			
			if(ac > r || (r == ac && END - aux <= i - aux)){
				r = ac;
				INI = aux;
				END = i;
			}if(ac < 0){
				aux = i + 1;
				ac = 0;
			}
		}
		
		printf("Teste %d\n", ++k);
		
		if(r > 0)
			printf("%d %d", INI + 1, END + 1);
		else
			printf("nenhum");
			
		printf("\n\n");
	}

	return 0;
}
