#include <stdio.h>
#define MAX 101
#define INFINITY 99999999

int G[MAX][MAX], dis[MAX][MAX], N = 0;

inline int min(int a, int b){
	return a < b ? a : b;
}

inline void arc(int v, int w, int c){
	G[v][w] = c;
}

void FloydWarshall(){

	int k = 0, v = 0, w = 0;

	for(v = 0; v < N; v++)
		for(w = 0; w < N; w++)
			dis[v][w] = G[v][w];

	for(k = 0; k < N; k++)
		for(v = 0; v < N; v++)
			for(w = 0; w < N; w++)
				dis[v][w] = min(dis[v][w], dis[v][k] + dis[k][w]);

}

int main(){

	scanf("%d", &N);

	int E = 0, T = 0, m = 0, R = 0,
		v = 0, w = 0, c = 0;

	for(v = 0; v < N; v++)
		for(w = 0; w < N; w++)
			G[v][w] = v == w ? 0 : INFINITY;

	scanf("%d", &E);
	scanf("%d", &T);
	scanf("%d", &m);

	while(m--){
		scanf("%d %d %d", &v, &w, &c);
		arc(v - 1, w - 1, c);
	}

	E--;
	
	FloydWarshall();

	for(v = 0; v < N; v++){
		if(dis[v][E] <= T)
			R++;
	}

	printf("%d\n", R);

	return 0;
}
