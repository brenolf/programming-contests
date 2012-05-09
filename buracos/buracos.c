#include <stdio.h>
#include <stdlib.h>
#define M 4000

int G[M][M], I[M][M], visG[M], visI[M], ct = 0;

inline void push(int v, int w){
	int a = G[v][0] + 1, i = 1, yes = 1;
	
	for(i;i<a;i++)
		if(G[v][i] == w){
			yes = 0;
			break;
		}
	
	if(yes){
		G[v][a] = w;
		G[v][0]++;
	}
	
	a = I[w][0] + 1, yes = 1;
	
	for(i=1;i<a;i++)
		if(I[w][i] == v){
			yes = 0;
			break;
		}
	
	if(yes){
		I[w][a] = v;
		I[w][0]++;
	}
}

void dfsG(int v){		
	
	visG[v] = 1;
	
	ct++;
	
	int i = 1, w = 0;
	
	for(i;i<=G[v][0];i++){
		w = G[v][i];
		if(!visG[w])
			dfsG(w);
	}
}

void dfsI(int v){		
	
	visI[v] = 1;
	
	ct++;
	
	int i = 1, w = 0;
	
	for(i;i<=I[v][0];i++){
		w = I[v][i];
		if(!visI[w])
			dfsI(w);
	}
}

int main(){
	
	
	int i = 0, n = 0, m = 0, v = 0, w = 0, k = 0;

	
	while(1){
		
		scanf("%d %d", &n, &m);
		
		if(!n && !m)break;
		
		for(i=0;i<n;i++){
			visG[i] = 0;
			visI[i] = 0;
			
			G[i][0] = 0;
			I[i][0] = 0;
		}
		
		for(i=0;i<m;i++){
			scanf("%d %d", &v, &w);
			push(v-1, w-1);
		}
		
		ct = 0;
		dfsG(0);
		
		printf("Teste %d\n", ++k);
		if(ct == n){
			ct = 0;
			dfsI(0);
			
			if(ct == n)printf("S\n\n");
			else printf("N\n\n");
		}else printf("N\n\n");
	}

	return 0;
}
