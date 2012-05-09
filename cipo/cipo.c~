#include <stdio.h>

#define MAXV 1001
#define MAXE 2000001
#define INFTY 11000

typedef struct {
	short v, w, c;
} Edge;

Edge G[MAXE], classes[3][MAXE];
int N = 0, M = 0;
int id[MAXV], sz[MAXV], classesI[3] = {0, 0, 0}, GI = 0;
short H[MAXV][MAXV];

void newEdge(short v, short w, short c){
	if(c < H[v][w]){
		H[v][w] = c;
		H[w][v] = c;

		int i = ((c == 1235) ? 0 : ((c == 8977) ? 1 : 2));
		
		classes[i][classesI[i]].v = v;
		classes[i][classesI[i]].w = w;
		classes[i][classesI[i]].c = c;
		
		classesI[i]++;
	}
}

int kruskal(){
	int k = 0, i = 0, fv = 0, fw = 0, COST = 0;

	for(i = 0; i < N; i++){
		id[i] = i;
		sz[i] = 1;
	}

	for(i = k = 0; k < N - 1 && i < GI; i++){

		for(fv = G[i].v; fv != id[fv]; fv = id[fv]);
		for(fw = G[i].w; fw != id[fw]; fw = id[fw]);
		
		if(fv != fw){
			if(sz[fv] < sz[fw]){
				id[fv] = fw;
				sz[fw] += sz[fv];
			}else{
				id[fw] = fv;
				sz[fv] += sz[fw];
			}
			
			COST += G[i].c;
			k++;
		}
	}
	
	return COST;
}

int main(){
	int i = 0, j = 0, k = 1;
	short x = 0, y = 0, z = 0;
	
	while(scanf("%d %d", &N, &M) == 2){
		classesI[0] = 0;
		classesI[1] = 0;
		classesI[2] = 0;
	
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				H[i][j] = INFTY;
			}
			
			id[i] = i;
			sz[i] = 1;
		}
		
		while(M--){
			scanf("%hd %hd %hd", &x, &y, &z);
			newEdge(x - 1, y - 1, z);
		}

		GI = 0;
		for(i = 0; i < 3; i++)
			for(j = 0; j < classesI[i]; j++)
				G[GI++] = classes[i][j];
		
		printf("Instancia %d\n%d\n\n", k++, kruskal());
	}

	return 0;
}
