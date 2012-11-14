#include <stdio.h>
#define MAX 7

int G[MAX][MAX], vis[MAX], adj[MAX], N = 0;

inline int edge(int v, int w){
	adj[v]++;
	adj[w]++;
	
	G[v][w] = 1;
	G[w][v] = 1;
}

int dfs(int v){
	vis[v] = 1;
	int i = 0, w = 0, c = 0;
	
	for(w = 0; w < MAX; w++){
		if(!G[v][w])
			continue;
			
		if(!vis[w])
			dfs(w);
	};
	
	for(i = 0; i < MAX; i++)
		c += vis[i];
		
	return c == N;
}

int main(){
	
	int i = 0, j = 0, n = 0, s = -1, c = 0, k = 1, v = 0, w = 0, impares = 0;
	
	while(1){
		
		scanf("%d", &n);
		
		if(!n)
			break;
			
		for(i = 0; i < MAX; i++){
			vis[i] = 0;
			adj[i] = 0;
			
			for(j = 0; j < MAX; j++)
				G[i][j] = 0;
		}
		
		s = -1;
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &v, &w);
			edge(v, w);
			s = s < 0 ? v : s;
		}
		
		impares = 0;
		N = 0;
		
		for(i = 0; i < MAX; i++){
			if(adj[i]){
				impares += (adj[i] % 2 != 0) ? 1 : 0;
				N++;
			}
		}
		
		printf("Teste %d\n", k++);	
			
		if(impares <= 2 && dfs(s))
			printf("sim\n\n");
		else
			printf("nao\n\n");
	};

	return 0;
}
