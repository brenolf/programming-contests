// Breno Lima de Freitas

#include <stdio.h>
#include <stdlib.h>
#define MAX 20001
#define INFINITY 200000001

int **G;
int prt[MAX], dis[MAX], frj[MAX];

int n = 0, S = 0, T = 0;

void arc(int v, int w, int W){
	G[v][w] = W;
}

void edge(int v, int w, int W){
	arc(v, w, W);
	arc(w, v, W);
}

void dijkstra(){
	int v = 0, w = 0, min = -1;

	for(w = 0; w < n; w++){
		prt[w] = -1;
		frj[w] = S;
		dis[w] = G[S][w];
	}
	
	dis[S] = 0;
	prt[S] = S;
	
	while(1){
		min = INFINITY;
		
		for(w = 0; w < n; w++){
			if(prt[w] < 0 && min > dis[w]){
				min = dis[w];
				v = w;
			}
		}
		
		if(min == INFINITY || v == T)
			break;
			
		prt[v] = frj[v];
		
		for(w = 0; w < n; w++){
			if(dis[w] > dis[v] + G[v][w]){
				dis[w] = dis[v] + G[v][w];
				frj[w] = v;
			}
		}
	}
}

int main(){
	int N = 0, i = 0, j = 0, k = 1, v = 0, w = 0, W = 0;
	int m = 0;
	
	G = (int**) malloc(sizeof(int*) * MAX);
	
	for(i = 0; i < MAX; i++)
		G[i] = (int*) malloc(sizeof(int) * MAX);
	
	scanf("%d", &N);
	
	while(N--){
		scanf("%d %d %d %d", &n, &m, &S, &T);	
		
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				G[i][j] = INFINITY;
		
		while(m--){
			scanf("%d %d %d", &v, &w, &W);
			edge(v, w, W);
		}
		
		dijkstra();
		
		printf("Case #%d: ", k++);
		
		if(dis[T] == INFINITY)
			printf("unreachable\n");
		else
			printf("%d\n", dis[T]);
	}

	return 0;
}
