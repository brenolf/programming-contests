#include <stdio.h>
#define MAX 41

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){

	int n = 0, m = 0, g = 0, i = 0, j = 0, maior = -1;
	int times[MAX];
	char c;

	while(1){

		scanf("%d %d %d", &n, &m, &g);

		if(!n && !m && !g)
			break;

		for(i = 0; i < n; i++)
			times[i] = 0;

		maior = -1;

		while(g--){
			scanf("%d %c %d", &i, &c, &j);

			times[j]++;

			if(c == '='){
				times[i]++;
				times[j]++;
			}else
				times[j]++;

			maior = max(maior, times[i]);
			maior = max(maior, times[j]);
		}

	}

	return 0;
}