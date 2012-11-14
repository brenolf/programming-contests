#include <stdio.h>
#define MAX 1002

int G[MAX][MAX], vis[MAX], adj[MAX];

void arc(int v, int w){
	G[v][w] = 1;

	adj[v]++;
	adj[w]++;
}

int main(){
	
	int n = 0, m = 0, s = 0;
	int i = 0, j = 0;

	while(scanf("%d %d", &n, &m) != EOF){

		for(i = 0; i < n; i++){
			vis[i] = 0;
			adj[i] = 0;

			for(j = 0; j < n; j++)
				G[i][j] = 0;
		}		

		for(i = 0; i < m; i++){
			scanf("%d %d", &v, &w);
			arc(v - 1, w - 1);
		}

		s = 0;
		for(i = 1; i < n; i++)
			if(adj[i] < adj[s])
				s = i;


		

	}

	return 0;
}