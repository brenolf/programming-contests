#include <stdio.h>
#include <stdlib.h>

int isb(int **g, int len, int v, int c, int *lb){
	int i = 0;
	
	lb[v] = 1 - c;
	
	for(i=0;i<len;i++){
		if(!g[v][i])continue;
		
		if(lb[i]<0){
			if(!isb(g, len, i, lb[v], lb))return 0;
		}else if(lb[i] == lb[v])return 0;
	}
	
	return 1;
}

int main(){
	int **g = (int**) malloc(100 * sizeof(int*)), 
	*lb = (int*) malloc(100 * sizeof(int)), 
	i = 0, j = 0, n = 0, m = 0, a1 = 0, a2 = 0, k = 0;

	for(i=0;i<100;i++)	
		g[i] = (int*) malloc(100 * sizeof(int));

	while(scanf("%d %d", &n, &m) != EOF){
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)g[i][j] = 0;
			lb[i] = -1;
		}
		
		for(i=0;i<m;i++){
			scanf("%d %d", &a1, &a2);
			g[a1-1][a2-1] = 1;
			g[a2-1][a1-1] = 1;
		}
		
		printf("Instancia %d\n", ++k);
		printf("%s\n\n", isb(g, n, 0, 1, lb)?"sim":"nao");
	}

	return 0;
}
