#include <stdio.h>

int main(){
	
	int n = 0, c = 0, k = 0, i = 0, j = 0, r = 0, sort[101], menor = 0;
	
	while(1){
		scanf("%d %d %d", &n, &c, &k);
		
		if(!n && !c && !k)
			break;
		
		for(i = 0; i <= k; i++)
			sort[i] = 0;
			
		for(i = 0; i < n; i++){
			for(j = 0; j < c; j++){
				scanf("%d", &r);
				getchar();
				sort[r]++;
			}
		}
		
		menor = 999999999;
		
		for(i = 1; i <= k; i++){
			if(sort[i] < menor)
				menor = sort[i];
		}
		
		for(i = 1; i <= k; i++){
			if(sort[i] == menor){
				printf("%d", i);
				
				if(i + 1 <= k)
					printf(" ");
			}
		}
			
		printf("\n");
	}

	return 0;
}
