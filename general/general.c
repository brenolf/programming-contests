// Breno Lima de Freitas 408433

#include <stdio.h>
#define MAX 100001

int M[MAX], aux[MAX], w[MAX];
unsigned long long S = 0;

void merge(int ini, int meio, int fim){
	int i = 0, j = 0, k = 0;

	for(i = ini; i < meio; i++)
		w[k++] = aux[i];

	for(i = fim - 1; i >= meio; i--)
		w[k++] = aux[i];

	k--;

	for(i = ini; i < fim; i++){
		if(w[j] <= w[k])
			aux[i] = w[j++];
		else{
			aux[i] = w[k--];
			S += meio - ini - j;
		}
	}
}

void mergesort(int ini, int fim){
	if(ini >= fim - 1)
		return;

	int meio = (ini + fim) / 2;

	mergesort(ini, meio);
	mergesort(meio, fim);
	merge(ini, meio, fim);
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

			mergesort(0, c);

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