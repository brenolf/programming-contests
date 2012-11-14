// Breno Lima de Freitas

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MAX 100005

using namespace std;

vector<int> G[MAX];
int PD[MAX][2], n = 0;

inline void edge(int v, int w){
	G[v].push_back(w);
	G[w].push_back(v);
}

inline int min(int a, int b){
	return a < b ? a : b;
}

int cover(int v, int prt, int from){
	if(PD[v][from] != -1)
		return PD[v][from];
	
	int i = 0, aux = 0;
	PD[v][from] = 0;
	
	if(from){
		for(i = 0; i < G[v].size(); i++){
			if(G[v][i] != prt)
				PD[v][1] += cover(G[v][i], v, 0);
		}
		
		aux = 1;
		
		for(i = 0; i < G[v].size(); i++){
			if(G[v][i] != prt)
				aux += cover(G[v][i], v, 1);
		}
		
		PD[v][1] = min(PD[v][1], aux);
	}else{
		PD[v][0] = 1;
		
		for(i = 0; i < G[v].size(); i++){
			if(G[v][i] != prt)
				PD[v][0] += cover(G[v][i], v, 1);
		}	
	}
	
	return PD[v][from];
}

int main(){
	int v = 0, w = 0,
	i = 0, j = 0, r[2] = {1, 0};
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++){
		G[i].clear();
		
		PD[i][0] = -1;
		PD[i][1] = -1;
	}
	
	for(i = 1; i < n; i++){
		scanf("%d %d", &v, &w);
		edge(v - 1, w - 1);
	}
	
	for(i = 0; i < G[0].size(); i++)
		r[0] += cover(G[0][i], 0, 1);
			
	for(i = 0; i < G[0].size(); i++)
		r[1] += cover(G[0][i], 0, 0);

	printf("%d\n", min(r[0], r[1]));
	
	return 0;
}
