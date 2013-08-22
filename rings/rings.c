// UVA Rings and Glue

#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y, r;
} Circle;

Circle vet[101];
Circle p, q;

int G[101][101], n = 0;
int vis[101];

void edge(int v, int u){
	G[u][v] = 1;
	G[v][u] = 1;
}

int max(int a, int b){
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

	int i, j, maior = 0, v;
	double dist, c_maior, c_menor, R;

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
					c_maior = p.r > q.r ? p.r : q.r;
					c_menor = p.r < q.r ? p.r : q.r;

					if(dist < R && dist + c_menor > c_maior)
						edge(i, j);
				}
			}
		}

		maior = 0;

		for(v = 0; v < n; v++)
			if(!vis[v])
				maior = max(maior, dfs(v));

		printf("The largest component contains %d ring%s.\n", maior, (maior == 1 ? "" : "s"));
	}

	return 0;
}
