#include <stdio.h>
#include <stdlib.h>

int V[10000];

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){
	
	int i = 0, n = 0, m = 0;
	
	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++)
		scanf("%d", &V[i]);

	qsort(V, n, sizeof(int), cmp);

	for(i = n - 1; i > n - 1 - m; i--)
		printf("%d\n", V[i]);

	return 0;
}
