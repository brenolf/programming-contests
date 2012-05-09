#include <stdio.h>
#include <stdlib.h>

int hasPath(int** g, int len, int a, int* vis, int* r, int isInv){
	int i = 0, cond = isInv;
	
	vis[a] = isInv?0:1;
	(*r)++;
	
	for(i=0;i<len;i++){
		if(g[a][i] && vis[i]==cond){
			hasPath(g, len, i, vis, r, isInv);
		}
	}
}

int main(){
	
	int **g, **inv, vis[2001], 
	i = 0, j = 0, n = 0, m = 0, v = 0, w = 0, p = 0, a = 0, r = 0;
	
	g = (int**) malloc(sizeof(int*) * 2001);
	inv = (int**) malloc(sizeof(int*) * 2001);
	
	for(i=0;i<2001;i++){
		vis[i] = 0;
		g[i] = (int*) calloc(2001, sizeof(int));
		inv[i] = (int*) calloc(2001, sizeof(int));
	}
	
	while(1){
		
		scanf("%d %d", &n, &m);
		
		if(!n && !m)break;
		
		r = 0;
		
		for(i=0;i<n;i++){
			vis[i] = 0;
			for(j=0;j<n;j++)g[i][j] = 0;
			for(j=0;j<n;j++)inv[i][j] = 0;
		}
		
		for(i=0;i<m;i++){
			scanf("%d %d %d", &v, &w, &p);
			
			if(!i)a = v;
			
			g[v-1][w-1] = 1;
			if(p==2)g[w-1][v-1] = 1;
			
			inv[w-1][v-1] = 1;
			if(p==2)inv[v-1][w-1] = 1;
		}
		
		hasPath(g, n, a, vis, &r, 0);
		
		if(r!=n)printf("0\n");
		else{
			r = 0;
			hasPath(inv, n, a, vis, &r, 1);
			printf("%d\n", r!=n?0:1);
		}
	}

	return 0;
}
