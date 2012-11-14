/*
 * Treinamento Maratona 2012 - Problema B - O Código Secreto
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */
 
#include <stdio.h>
#define MAX 100001

typedef struct {
	int i, v;
} Item;

int cmp(const void *pa, const void *pb){
	Item a = *(Item*)pa, b = *(Item*)pb;
	return a.v - b.v;
}

int main(){
	
	int i = 0, n = 0, x = 0, r = 0, prox = 0, ant = 0, N = 0;
	Item c[MAX], e[MAX], R[MAX];
	
	while(1){
		scanf("%d %d", &n, &x);
		
		if(!n && !x)
			break;
		
		for(i = 0; i < x; i++){
			c[i].v = 0;
			c[i].i = i;
		}
			
		for(i = 0; i < x; i++){
			scanf("%d", &r);
			getchar();
			c[r].v++;
		}
		
		for(i = 0; i < n; i++){
			scanf("%d", &e[i].v);
			getchar();
			e[i].i = i;
		}
		
		qsort(c, n, sizeof(Item), cmp);
		qsort(e, n, sizeof(Item), cmp);
		
		N = 0;
		
		for(i = n - 1; i >= 0; i--){
			
			prox = i + 1 >= n ? n - 1 : i + 1;
			ant = i - 1 < 0 ? 0 : i - 1;
			
			if((prox == i && c[ant].v != c[i].v) || (ant == i && c[prox].v != c[i].v) || (c[prox].v != c[i].v && c[ant].v != c[i].v)){
				// Gambiarra por preguiça
				R[N].v = c[i].i;
				R[N].i = e[i].i;
				N++;
			}
		}
		
		qsort(R, N, sizeof(Item), cmp);
		
		for(i = 0; i < N; i++){
			printf("(%d,%d)", R[i].v, R[i].i);
			
			if(i + 1 < N)
				printf(" "); // :'(
		}
		
		if(!N)
			printf("NENHUM");
		
		printf("\n");
		
	}
	
	return 0;
}
