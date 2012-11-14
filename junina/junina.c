#include <stdio.h>
#define MAX 21

int G[MAX][MAX], T[MAX], n = 0;

inline void arc(int v, int w){
	G[v][w] = 1;
	G[w][v] = 1;
}

int backtrack(int v){
	int i = 0, j = 0, r = v, candidato = 0, new = 0;

	if(v)
		i = T[v - 1] + 1;

	for(; i < n; i++){
		candidato = !G[i][i];

		for(j = 0; candidato && j < v; j++)
			candidato = !G[i][T[j]];

		if(candidato){
			T[v] = i;

			v++;

			new = backtrack(v);

			if(new > r)
				r = new;

			v--;
		}
	}

	return r;
}

int main(){
	
	int v = 0, i = 0, j = 0, k = 1, R = 0;

	while(1){
		
		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
				G[i][j] = 0;
		}

		i = 0;
		R = n;

		while(n--){
			while(1){
				scanf("%d", &v);
				getchar();

				if(!v)
					break;

				arc(i, v - 1);
			}
			i++;
		}

		n = R;

		printf("Teste %d\n%d\n\n", k++, backtrack(0));
	}


	return 0;
}