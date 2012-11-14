#include <stdio.h>
#define MAX 2001

#define BRANCO -1
#define CINZA 0
#define PRETO 1

int G[MAX][MAX], cor[MAX], N = 0;

int isBipartite(int v, int C){
	int w = 0;

	cor[v] = (C == PRETO) ? CINZA : PRETO;

	for(w = 0; w < N; w++){
		if(!G[v][w])
			continue;

		if(cor[w] == BRANCO){
			if(!isBipartite(w, cor[v]))
				return 0;
		}else if(cor[w] == cor[v])
			return 0;
	}

	return 1;
}

int main(){
	int i = 0, j = 0, q = 0, m = 0, v = 0, w = 0, k = 1, allBipartite = 0;

	scanf("%d", &q);

	while(q--){

		scanf("%d %d", &N, &m);

		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				G[i][j] = 0;
			}

			cor[i] = BRANCO;
		}

		for(i = 0; i < m; i++){
			scanf("%d %d", &v, &w);

			v--;
			w--;

			G[v][w] = 1;
			G[w][v] = 1;
		}

		printf("Scenario #%d:\n", k++);

		allBipartite = 1;

		for(i = 0; i < N; i++){
			if(cor[i] == BRANCO){
				if(!isBipartite(i, CINZA)){
					allBipartite = 0;
					break;
				}
			}
		}

		if(allBipartite)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");

	}

	return 0;
}