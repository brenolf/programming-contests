#include <stdio.h>
#define MAX 102
#define INFINITY 99999999

int N = 0, G[MAX][MAX], dis[MAX][MAX][MAX];

inline int min(int a, int b){
	return a < b ? a : b;
}

inline void arc(int v, int w, int c){
	G[v][w] = c;
}

void FloydWarshall(){
	int i = 0, k = 0, v = 0, w = 0;

	for(i = 0; i <= N; i++)
		for(v = 0; v < N; v++)
			for(w = 0; w < N; w++)
				dis[i][v][w] = G[v][w];


	for(i = 0; i <= N; i++)
		for(k = 0; k < i; k++)
			for(v = 0; v < N; v++)
				for(w = 0; w < N; w++)
					dis[i][v][w] = min(dis[i][v][w], dis[i][v][k] + dis[i][k][w]);
}

int main(){
	int m = 0, v = 0, w = 0, c = 0, t = 0, k = 1, menor = 0;


	while(scanf("%d %d", &N, &m) != EOF){

		for(v = 0; v < N; v++)
			for(w = 0; w < N; w++)
				arc(v, w, (v == w ? 0 : INFINITY));

		while(m--){
			scanf("%d %d %d", &v, &w, &c);
			arc(v - 1, w - 1, min(G[v - 1][w - 1], c));
		}

		FloydWarshall();

		scanf("%d", &c);

		printf("Instancia %d\n", k++);

		while(c--){
			scanf("%d %d %d", &v, &w, &t);

			menor = dis[t][v - 1][w - 1];

			if(menor == INFINITY)
				menor = -1;

			printf("%d\n", menor);
		}

		printf("\n");
	}

	return 0;
}
