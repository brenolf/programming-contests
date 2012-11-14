#include <stdio.h>
#define MAX 1001

int G[MAX][MAX], vis[MAX], n = 0;

void edge(int v, int w){
	G[v][w] = 1;
	G[w][v] = 1;
}

void dfs(int v){

	vis[v] = 1;

	int w = 0;

	for(w = 0; w < n; w++)
		if(G[v][w] && !vis[w])
			dfs(w);
}

int main(){
	
	int m = 0;
	int i = 0, j = 0;
	int v = 0, w = 0;
	int R = 0;

	scanf("%d %d", &n, &m);


	for(i = 0; i < n; i++){
		vis[i] = 0;

		for(j = 0; j < n; j++)
			G[i][j] = 0;
	}

	for(i = 0; i < m; i++){
		scanf("%d %d", &v, &w);
		edge(v - 1, w - 1);
	}

	for(i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
			R++;
		}
	}

	printf("%d", R);

	return 0;
}