#include <stdio.h>
#define MAX 101
#define INFTY 9999999

int G[MAX][MAX], prt[MAX], dis[MAX], frj[MAX], n = 0;

inline void arc(int v, int w, int c){
	G[v][w] = c;
}

inline int dijkstra(int s, int f){
	int w = 0, v = 0, min = 0;
	
	for(w = 0; w < n; w++){
		prt[w] = -1;
		frj[w] = s;
		dis[w] = G[s][w];
	}
	
	prt[s] = s;
	dis[s] = 0;
	
	while(1){
		min = INFTY;
		
		for(w = 0; w < n; w++)
			if(prt[w] < 0 && min > dis[w]){
				v = w;
				min = dis[v];
			}
		
		if(min == INFTY)
			break;
			
		prt[v] = frj[v];
		
		for(w = 0; w < n; w++)
			if(dis[w] > dis[v] + G[v][w]){
				dis[w] = dis[v] + G[v][w];
				frj[w] = v;
			}
	}
	
	return dis[f] == INFTY ? -1 : dis[f];
}

int main(){
	
	int i = 0, j = 0, m = 0, v = 0, w = 0, c = 0, s = 0, d = 0;
	
	while(1){
		scanf("%d %d", &n, &m);
		
		if(!n && !m)
			break;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				G[i][j] = INFTY;
			
		while(m--){
			scanf("%d %d %d", &v, &w, &c);
			arc(v - 1, w - 1, c);
		}
		
		scanf("%d %d", &s, &d);
		
		printf("%d\n", dijkstra(s - 1, d - 1));
	}
	
	return 0;
}
