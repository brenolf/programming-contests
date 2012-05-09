#include <stdio.h>
#include <stdlib.h>
#define MX 1001

int min(int a, int b){
	return a<b?a:b;
}

int hasBridges(int v, int **g, int len, int *vis, int *prt, int *low, int *ct, int *r){
	int i = 0;

	vis[v] = (*ct)++;
	low[v] = vis[v];

	for(i=0;i<len;i++){
		if(g[v][i]){
			if(!vis[i]){
				prt[i] = v;
				hasBridges(i, g, len, vis, prt, low, ct, r);
				low[v] = min(low[i], low[v]);
				if(low[i] == vis[i])(*r)++;
			}else if(prt[v] != i)low[v] = min(low[v], vis[i]);
		}
	}
}

int main(){
	
	int **g, vis[MX], low[MX], prt[MX],
	i = 0, j = 0, n = 0, m = 0, v = 0, w = 0, ct = 0, r = 0;
	
	g = (int**) malloc(sizeof(int*) * MX);
	
	for(i=0;i<MX;i++){
		vis[i] = 0;
		prt[i] = 0;
		g[i] = (int*) calloc(MX, sizeof(int));
	}
	
	while(1){
		
		scanf("%d %d", &n, &m);
		
		if(!n && !m)break;
		
		for(i=0;i<n;i++){
			vis[i] = 0;
			low[i] = 0;
			prt[i] = 0;
			for(j=0;j<n;j++)g[i][j] = 0;
		}
		
		for(i=0;i<m;i++){
			scanf("%d %d", &v, &w);
			
			g[v-1][w-1] = 1;
			g[w-1][v-1] = 1;
		}
		
		r = 0;
		hasBridges(0, g, n, vis, prt, low, &ct, &r);
		
		if(r == 0)printf("S\n");
		else printf("N\n");
	}

	return 0;
}
