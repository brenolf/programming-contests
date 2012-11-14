#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	int x[MAX], y[MAX], n = 0, i = 0, k = 1;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		for(i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
			
		qsort(x, n, sizeof(int), cmp);
		qsort(y, n, sizeof(int), cmp);
		
		printf("Teste %d\n%d %d\n\n", k++, x[n / 2], y[n / 2]);
	};
	
	return 0;
}
