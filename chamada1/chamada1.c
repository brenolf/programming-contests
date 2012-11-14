#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b){
	return strcmp((char*)a, (char*)b);
}


int main(){

	int n = 0, k = 0, i = 0;
	char nomes[101][21];

	scanf("%d %d", &n, &k);

	for(i = 0; i < n; i++){
		scanf("%s", nomes[i]);
		getchar();
	}

	qsort(nomes, n, sizeof(char[21]), cmp);

	printf("%s", nomes[k - 1]);

	return 0;
}