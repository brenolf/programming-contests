#include <stdio.h>
#define MAX 151

int G[MAX][MAX], dist[MAX], vis[MAX], p = 0;

inline void arc(int v, int w){
	G[v][w] = 1;
}

int dfs(int v){
	int w = 0, atual = 0;

	vis[v] = 1;

	for(w = 0; w < p; w++){
		if(!G[v][w])
			continue;

		atual = 1;

		if(!vis[w])
			atual += dfs(w);
		else 
			atual += dist[w];

		if(atual > dist[v])
			dist[v] = atual;
	}

	return dist[v];
}

int main(){
	
	int l = 0, s = 0, i = 0, j = 0, v = 0, w = 0, k = 1;
	int custos[MAX];

	while(1){
		scanf("%d %d %d", &p, &l, &s);

		if(!p && !l && !s)
			break;

		s--;

		for(i = 0; i < p; i++){
			dist[i] = 0;
			vis[i] = 0;

			for(j = 0; j < p; j++)
				G[i][j] = 0;

			scanf("%d", &custos[i]);
			getchar();
		}

		while(l--){
			scanf("%d %d", &v, &w);
			v--;
			w--;

			if(custos[v] > custos[w])
				arc(v, w);
		}

		printf("Teste %d\n%d\n\n", k++, dfs(s));

	}
	

	return 0;
}