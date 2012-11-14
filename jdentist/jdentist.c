#include <stdio.h>
#include <stdlib.h>
#define MAX 10005

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

int main(){
	int i = 0, j = 0, n = 0, ini = 0, fim = 0, q = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d %d", &ini, &fim);
		push(ini, fim);
	}

	qsort(M, n, sizeof(Interval), cmp);

	j = 0;
	q = 1;

	for(i = 1; i < n; i++){
		if(M[i].ini >= M[j].fim){
			q++;
			j = i;
		}
		if(M[i].ini >= M[j].ini && M[i].fim <= M[j].fim)
			j = i;
	}

	printf("%d", q);

	return 0;
}