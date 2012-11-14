// Breno Lima de Freitas 408433

#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

int M[MAX], aux[MAX], w[MAX];
unsigned long long S = 0;

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

inline void inversoes(int l){
	int i = 0, j = 0;

	for(i = 0; i < l; i++){
		for(j = i + 1; j < l; j++){
			if(aux[j] < aux[i])
				S++;
		}
	}
}

int main(){
	int T = 0, n = 0, k = 0, i = 0, j = 0, c = 0, R = 0;

	scanf("%d", &T);
	getchar();

	while(T--){
		scanf("%d %d", &n, &k);
		getchar();

		for(i = 0; i < n; i++){
			scanf("%d", &M[i]);
			getchar();
		}

		S = 0;

		for(i = 0; i < k; i++){
			for(j = i, c = 0; j < n; j += k, c++)
				aux[c] = M[j];

			inversoes(c);
			qsort(aux, c, sizeof(int), cmp);

			for(j = i, c = 0; j < n; j += k, c++)
				M[j] = aux[c];
		}

		R = 1;

		for(i = 1; i < n; i++)
			if(M[i] < M[i - 1]){
				R = 0;
				break;
			}

		if(R)
			printf("%llu\n", S);
		else
			printf("impossivel\n");
	}

	return 0;
}