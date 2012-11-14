// Breno Lima de Freitas 408433

#include <stdio.h>
#define MAX 100001

int M[MAX], w[MAX], S = 0;

void merge(int ini, int meio, int fim){
	int i = 0, j = 0, k = 0;

	for(i = ini; i < meio; i++)
		w[k++] = M[i];

	for(i = fim - 1; i >= meio; i--)
		w[k++] = M[i];

	k--;

	for(i = ini; i < fim; i++){
		if(w[j] <= w[k])
			M[i] = w[j++];
		else{
			M[i] = w[k--];
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
	int n = 0, i = 0, j = 0;

	while(1){
		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		for(i = 0; i < n; i++){
			scanf("%d", &M[i]);
			getchar();
		}

		S = 0;

		mergesort(0, n);

		if(S % 2 == 0)
			printf("Carlos\n");
		else
			printf("Marcelo\n");
	}

	return 0;
}