/*
 * Treinamento Maratona 2012 - Problema C - Coffee Break
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */

#include <stdio.h>
#define MAX 1001
#define ALU 101

typedef struct {
	double peso, valor;
} Item;

int cmp(const void *pa, const void *pb){
	Item ia = *(Item*)pa, ib = *(Item*)pb;
	double a = 0, b = 0;
	
	a = ia.valor / ia.peso;
	b = ib.valor / ib.peso;
	
	if(a == b)
		return 0;
	
	if(a > b)
		return 1;
		
	return -1;
}

int main(){
	
	int i = 0, j = 0, n = 0, a = 0;
	double e[ALU], size = 0, atual = 0;
	Item mochila[MAX];
	
	while(1){
		scanf("%d %d", &n, &a);
		getchar();
		
		if(!n && !a)
			break;
			
		for(i = 0; i < n; i++){
			scanf("%lf", &mochila[i].valor);
			getchar();
		}
		
		for(i = 0; i < n; i++){
			scanf("%lf", &mochila[i].peso);
			getchar();
		}
		
		for(i = 0; i < a; i++){
			scanf("%lf", &e[i]);
			getchar();
		}
		
		qsort(mochila, n, sizeof(Item), cmp);
		
		for(j = 0; j < a; j++){
			
			size = e[j];
			atual = 0;
			
			for(i = n - 1; i >= 0; i--){
				if(mochila[i].peso <= size){
					atual += mochila[i].valor;
					size -= mochila[i].peso;
				}else{
					atual += (size / mochila[i].peso) * mochila[i].valor;
					size = 0;
				}
			}
			
			printf("%.4lf\n", atual);
		}
		
	}

	return 0;
}
