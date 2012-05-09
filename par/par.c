#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, ma = 0, mb = 0, i = 0, k = 0;
	char a[11], b[11];

	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		scanf("%s", a);
		scanf("%s", b);
		
		printf("Teste %d\n", ++k);
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &ma, &mb);
			
			if((ma + mb) % 2 == 0)
				printf("%s\n", a);
			else
				printf("%s\n", b);
		}
		
		printf("\n");
	}

	return 0;
}

