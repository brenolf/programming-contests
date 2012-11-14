// Breno Lima de Freitas 408433

#include <stdio.h>
#define MAX 100005

int M[MAX], s[MAX], cache[MAX], n = 0, m = 0;

inline int max(int a, int b){
	return a > b ? a : b;
}

int row(int i){
	if(i >= m)
		return 0;

	if(cache[i] >= 0)
		return cache[i];

	cache[i] = max(M[i] + row(i + 2), row(i + 1));
	return cache[i];
}

int best(int i){
	if(i >= n)
		return 0;

	if(cache[i] >= 0)
		return cache[i];

	cache[i] = max(s[i] + best(i + 2), best(i + 1));
	return cache[i];
}

int main(){

	int i = 0, j = 0;

	while(1){
		scanf("%d %d", &n ,&m);
		getchar();

		if(!n && !m)
			break;

		for(i = 0; i < n; i++){
			s[i] = 0;
			for(j = 0; j < m; j++){
				cache[j] = -1;
				scanf("%d", &M[j]);
				getchar();
			}
			s[i] = row(0);
		}

		for(i = 0; i < n; i++)
			cache[i] = -1;

		printf("%d\n", best(0));
	}

	return 0;
}