#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int *M = malloc(sizeof(int) * MAX);
	int n = 0, i = 0, r = 0, e = 0, d = 0, maior = 0;

	while(1){
		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		for(i = 0; i < n; i++){
			scanf("%d", &M[i]);
			getchar();			
		}

		qsort(M, n, sizeof(int), cmp);

		e = 0;
		d = n - 1;

		maior = -1;

		while(e < d){
			r = M[e++] + M[d--];
			if(r > maior)
				maior = r;
		}

		printf("%d\n", maior);
	}

	return 0;
}