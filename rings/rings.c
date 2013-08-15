#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y, r;
} Circle;

Circle vet[101];
Circle p, q;

int G[101][101], n = 0;
int vis[101];

inline void edge(int v, int u){
	G[u][v] = 1;
	G[v][u] = 1;
}

inline int max(int a, int b){
	return a > b ? a : b;
}

int dfs(int v){
	int u, ret = 1, aux = 0;
	vis[v] = 1;

	for(u = 0; u < n; u++)
		if(G[v][u] && !vis[u])
			ret += dfs(u);

	return ret;
}

int main(){

	int i, j, maior = 0;
	double dist, R;

	while(1){
		scanf("%d", &n);

		if(n < 0)
			break;

		for(i = 0; i < n; i++){
			vis[i] = 0;

			for(j = 0; j < n; j++)
				G[i][j] = 0;
		}

		for(i = 0; i < n; i++)
			scanf("%lf %lf %lf", &vet[i].x, &vet[i].y, &vet[i].r);

		for(i = 0; i < n; i++){
			p = vet[i];

			for(j = 0; j < n; j++){
				if(j != i){
					q = vet[j];

					dist = sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
					R = p.r + q.r;

					if(dist <= R)
						edge(i, j);
				}
			}
		}

		maior = -1;

		for(i = 0; i < n; i++)
			if(!vis[i])
				maior = max(dfs(i), maior);

		printf("The largest component contains %d ring%s.", maior, (maior > 1 ? "s" : ""));
		printf("\n");
	}

	return 0;
}
