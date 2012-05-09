#include <stdio.h>
#include <stdlib.h>

#define M 101

int dfs(int **g, int len, int *vis, int v, int *ct){
	
	int i = 0;
	
	(*ct)++;
	
	vis[v] = 1;
	
	for(i=0;i<len;i++){
		if(g[v][i] && !vis[i])
				dfs(g, len, vis, i, ct);
	}
}

int main(){
	
	int i = 0, j = 0, e = 0, l = 0, x = 0, y = 0, a = 0, r = 0, k = 0,
	**g, vis[M];
	
	g = (int**) malloc(sizeof(int*) * M);
	
	for(i=0;i<M;i++){
		vis[i] = 0;
		g[i] = (int*) calloc(M, sizeof(int));
	}
	
	while(1){
		scanf("%d %d", &e, &l);
		
		if(!e && !l)break;
		
		for(i=0;i<e;i++){
			vis[i] = 0;
			for(j=0;j<e;j++)g[i][j] = 0;
		}
		
		for(i=0;i<l;i++){
			scanf("%d %d", &x, &y);
			
			if(i==0)a = x-1;
			
			g[x-1][y-1] = 1;
			g[y-1][x-1] = 1;
		}
		
		r = 0;
		
		dfs(g, e, vis, a, &r);
		
		printf("Teste %d\n", ++k);
		
		if(r != e)printf("falha\n\n");
		else printf("normal\n\n");
	}

	return 0;
}
