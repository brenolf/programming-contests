#include <stdio.h>
#include <vector>
#define M 10005

using namespace std;

int low[M], prt[M], vis[M], visH[M], R = 0, order = 0, sccN = 0;
vector<int>G[M];
vector<int>H[M];

int min(int a, int b){
	return a < b ? a : b;
}

void bridges(int v){
	int w = 0, i = 0;
	
	vis[v] = order;
	low[v] = order++;
	
	for(i = 0; i < (int) G[v].size(); i++){
		w = G[v][i];

		if(vis[w] < 0){
			prt[w] = v;
			bridges(w);
		
			low[v] = min(low[w], low[v]);
			
			if(low[w] == vis[w]){
				H[v].push_back(w);
				H[w].push_back(v);
			}
			
		}else if(prt[v] != w)
			low[v] = min(low[v], vis[w]);
	}
}

void dfs(int v){
	int w = 0, i = 0;

	visH[v] = sccN;

	for(i = 0; i < (int) H[v].size(); i++){
		w = H[v][i];
		
		if(visH[w] < 0)
			dfs(w);
	}
}

int main(){

	int i = 0, j = 0, c = 0, q = 0, v = 0, w = 0;
	
	while(1){
		scanf("%d %d %d", &R, &c, &q);
		
		if(!R && !c && !q)
			break;
		
		for(i = 0; i < R; i++){
			G[i].clear();
			H[i].clear();
			
			low[i] = -1;
			prt[i] = -1;
			vis[i] = -1;
			visH[i] = -1;
		}		
		
		order = 0;
		sccN = 0;

		for(i = 0; i < c; i++){
			scanf("%d %d", &v, &w);
			
			v--;
			w--;
			
			G[v].push_back(w);
			G[w].push_back(v);
		}
		
		for(i = 0; i < R; i++){
			if(vis[i] < 0){
				prt[i] = i;
				bridges(i);
			}
		}
		
		
		for(i = 0; i < R; i++){
			if(visH[i] < 0){
				sccN++;
				dfs(i);
			}
		}
		
		for(i = 0; i < q; i++){
			scanf("%d %d", &v, &w);

			if(visH[v - 1] == visH[w - 1])
				printf("Y\n");
			else
				printf("N\n");
		}
		
		printf("-\n");
		
	}

	return 0;
}
