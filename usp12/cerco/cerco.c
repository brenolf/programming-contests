#include <stdio.h>
#define MAX 1002
#define INFINITY 9999

int n = 0;
int G[MAX][MAX], peso[MAX], dis[MAX], vis[MAX];

double pot(double n, int p){
	int i = 0;
	double ret = 1;

	for(i = 1; i <= p; i++)
		ret *= n;

	return ret;
}

void edge(int v, int w){
	G[v][w] = 1;
	G[w][v] = 1;
}

void dijkstra(int ini, int end){
	int v = 0, w = 0, menor = 0;

	for(v = 0; v < n; v++){
		dis[v] = G[ini][v] ? peso[ini] + peso[v] : INFINITY;
		vis[v] = 0;
	}

	dis[ini] = 0;
	vis[ini] = 1;

	while(1){
		menor = INFINITY;

		for(v = 0; v < n; v++){
			if(!vis[v] && dis[v] < menor){
				w = v;
				menor = dis[w];
			}
		}

		if(menor == INFINITY || w == end)
			break;

		vis[w] = 1;

		for(v = 0; v < n; v++){
			if(!vis[v] && dis[v] > dis[w] + (G[w][v] ? peso[v] : INFINITY))
				dis[v] = dis[w] + peso[v];
		}
	}

}

int main(){

	int i = 0, j = 0, v = 0, w = 0;
	int m = 0, k = 0, a = 0, r = 0;
	double p = 0, P = 0;

	while(scanf("%d %d %d %lf", &n, &m, &k, &p) != EOF){
		for(i = 0; i < n; i++){
			peso[i] = 0;

			for(j = 0; j < n; j++)
				G[i][j] = 0;
		}

		for(i = 0; i < m; i++){
			scanf("%d %d", &v, &w);
			edge(v - 1, w - 1);
		}

		scanf("%d", &a);

		for(i = 0; i < a; i++){
			scanf("%d", &r);
			peso[r - 1]++;
		}

		scanf("%d %d", &v, &w);

		v--;
		w--;

		dijkstra(v, w);

		P = 0;

		if(dis[w] <= k)
			P = pot(p, dis[w]);

		printf("%.3lf\n", P);
	}

	return 0;
}