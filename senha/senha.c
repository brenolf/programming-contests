#include <stdio.h>

int main(){
	int M[7][10], n = 0, i = 0, j = 0, k = 1;
	int dig[10], maior[7];
	char e;

	while(1){
		scanf("%d", &n);
		getchar();

		if(!n)
			break;
			
		for(i = 0; i < 7; i++){
			maior[i] = 0;
			for(j = 0; j < 10; j++)
				M[i][j] = 0;
		}
		
		
		while(n--){
			for(i = 0; i < 10; i++){
				scanf("%d", &dig[i]);
				getchar();
			}
			
			for(i = 0; i < 6; i++){
				scanf("%c", &e);
				getchar();
				
				e -= 'A';
				
				if(M[i][maior[i]] < ++M[i][dig[2 * e]])
					maior[i] = dig[2 * e];
					
				if(M[i][maior[i]] < ++M[i][dig[2 * e + 1]])
					maior[i] = dig[2 * e + 1];
			}
		}
		
		printf("Teste %d\n", k++);

		for(i = 0; i < 6; i++)
			printf("%d ", maior[i]);
			
		printf("\n\n");
	}

	return 0;
}
