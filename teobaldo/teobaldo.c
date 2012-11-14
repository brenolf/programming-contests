#include <stdio.h>
#define MAX 105

int G[MAX][MAX], vis[MAX], prt[MAX];

inline void arc(int v, int w){
	int p = G[v][0], i = 0;
	
	for(i = 1; i < p; i++)
		if(G[v][i] == w)
			return;
			
	G[v][0]++;
	G[v][p] = w;
}

inline void edge(int v, int w){
	arc(v - 1, w - 1);
	arc(w - 1, v - 1);
}

int dfs(int s, int e, int d){
	int i = 0, w = 0;

	vis[s] = vis[prt[s]] + 1;
	
	for(i = 1; i < G[s][0]; i++){
		w = G[s][i];
		
		if(w == e && vis[w] == d)
			return 1;

		prt[w] = s;
		if(dfs(w, e, d))
			return 1;
	}

	return 0;
}

int main(){
	int c = 0, l = 0, i = 0, a = 0, b = 0, s = 0, e = 0, d = 0;
	
	while(1){
		scanf("%d %d", &c, &l);
		
		if(!c && !l)
			break;
		
		for(i = 0; i < c; i++){
			G[i][0] = 0;
			vis[i] = 0;
			prt[i] = 0;
		}
			
		for(i = 0; i < l; i++){
			scanf("%d %d", &a, &b);
			edge(a, b);
		}
		
		scanf("%d %d %d", &s, &e, &d);
		getchar();

		prt[s] = s;
		vis[s] = 1;

		printf(dfs(s, e, d) ? "No, Teobaldo can not travel.\n" : "Yes, Teobaldo can travel.\n");
	}

	return 0;
}