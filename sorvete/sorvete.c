#include <stdio.h>
#include <stdlib.h>
#define MAX 5005

typedef struct {
	int ini, fim;
} Interval;

Interval M[MAX];
int top = 0;

inline void push(int ini, int fim){
	M[top].ini = ini;
	M[top++].fim = fim;
}

int cmp(const void *a, const void *b){
	Interval i1 = *(Interval*)a, i2 = *(Interval*)b;
	int dif = i1.ini - i2.ini;

	if(dif)
		return dif;

	return i1.fim - i2.fim;
}

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int p = 0, s = 0, i = 0, j = 0, ini = 0, fim = 0, k = 1;

	while(1){
		scanf("%d %d", &p, &s);

		if(!p && !s)
			break;

		top = 0;

		for(i = 0; i < s; i++){
			scanf("%d %d", &ini, &fim);

			push(ini, fim);
		}

		qsort(M, s, sizeof(Interval), cmp);

		printf("Teste %d\n", k++);

		j = 0;

		for(i = 1; i < s; i++){
			if(M[i].ini <= M[j].fim)
				M[j].fim = max(M[j].fim, M[i].fim);
			else{
				printf("%d %d\n", M[j].ini, M[j].fim);
				j = i;
			}
		}

		printf("%d %d\n", M[j].ini, M[j].fim);

		printf("\n\n");
	}

	return 0;
}