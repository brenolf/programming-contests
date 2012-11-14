#include <stdio.h>
#define MAX 10001

int vet[MAX];
long long pd[2][MAX];

inline long long max(long long a, long long b){
	return a > b ? a : b;
}

inline long long min(long long a, long long b){
	return a < b ? a : b;
}

long long melhor(int ini, int fim, int primeiro){

	if(pd[ini][fim] != INF)
		return pd[ini][fim];


	int p = vet[ini], u = vet[fim];

	if(fim == ini + 1){
		if(primeiro)
			return (pd[ini][fim] = max(p, u));
		else
			return (pd[ini][fim] = min(p, u));
	}

	if(primeiro)
		return (pd[ini][fim] = max(p + melhor(ini + 1, fim, 0), melhor(ini, fim - 1, 0) + u));

	return (pd[ini][fim] = min(melhor(ini + 1, fim, 1), melhor(ini, fim - 1, 1)));
}


int main(){

	int N = 0, player = 0, k = 0, i = 0, j = 0;

	while(scanf("%d", &N) != EOF){
		for(i = 0; i < N; i++){
			scanf("%d", &vet[i]);
		}

		for(i = 0; i < N - 1; i++)
			pd[i][i + 1] = max(vet[i], vet[i + 1]);


		for(k = 2; k < N; k += 2){
			
		}

		printf("%lld\n", melhor(0, N - 1, 1));
	}

	return 0;
}