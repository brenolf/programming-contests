#include <stdio.h>
#define MAX 1001
#define INFINITY 90000000

int G[MAX][MAX], E[MAX][MAX], queue[MAX], bottom = 0, top = 0,
	dis[MAX], vis[MAX],
	N = 0, K = 0;

inline void push(int v){
	queue[bottom++] = v;
}

inline int empty(){
	return top == bottom;
}

inline int shift(){
	return queue[top++];
}

inline void arc(char graph, int v, int w, int c){
	if(graph == 'G')
		G[v][w] = c;
	else if(graph == 'E')
		E[v][w] = c;
}

inline void edge(char graph, int v, int w, int c){
	arc(graph, v, w, c);
	arc(graph, w, v, c);
}

inline int cost(int v, int w){
	if(!E[v][w] && !E[w][v])
		return 0;

	int tempo = dis[v] + K;
	int ini = 0, fim = 0;

	int arcs[2] = {E[v][w], E[w][v]}, norma[2] = {G[v][w], G[w][v]};
	int i = 0;

	for(i = 0; i < 2; i++){
		if(arcs[i]){
			ini = arcs[i] - norma[i];
			fim = arcs[i];

			if(ini <= tempo && fim >= tempo){
				if(tempo >= ini && tempo < fim)
					return fim - tempo;

				return 0;
			}
		}
	}

	return 0;
}

void dijkstra(int r, int t){

	int v = 0, w = 0, min = 0;

	dis[r] = 0;
	vis[r] = 1;

	for(v = 0; v < N; v++){
		if(v != r){
			vis[v] = 0;
			dis[v] = G[r][v] + cost(r, v);
		}
	}

	while(1){

		min = INFINITY;

		for(v = 0; v < N; v++){
			if(!vis[v] && dis[v] < min){
				w = v;
				min = dis[w];
			}
		}

		if(min == INFINITY || w == t)
			break;

		vis[w] = 1;

		for(v = 0; v < N; v++){
			if(!vis[v] && dis[v] > dis[w] + G[w][v] + cost(w, v))
				dis[v] = dis[w] + G[w][v] + cost(w, v);
		}

	}

}

int main(){

	int m = 0, a = 0, b = 0, g = 0, v = 0, w = 0, c = 0, ac = 0;

	scanf("%d %d", &N, &m);
	scanf("%d %d %d %d", &a, &b, &K, &g);

	a--;
	b--;

	for(v = 0; v < N; v++)
		for(w = 0; w < N; w++){
			E[v][w] = 0;
			G[v][w] = INFINITY;
		}

	v = w = 0;

	while(g--){
		scanf("%d", &v);
		push(v - 1);
	}

	while(m--){
		scanf("%d %d %d", &v, &w, &c);
		edge('G', v - 1, w - 1, c);
	}

	v = shift();
	ac = 0;

	while(!empty()){
		w = shift();
		ac += G[v][w];
		arc('E', v, w, ac);
		v = w;
	}

	dijkstra(a, b);

	printf("%d", dis[b]);

	return 0;
}
