#include <stdio.h>

int main(){
	int n = 0, i = 0, t = 0, ant = 0, atual = 0, prox = 0;
	
	scanf("%d", &n);
	scanf("%d", &atual);
	
	for(i = 1; i < n; i++){
		scanf("%d", &prox);
	
		printf("%d\n", ant + atual + prox);
		
		ant = atual;
		atual = prox;
		prox = 0;
	}
	
	printf("%d\n", ant + atual + prox);

	return 0;
}
