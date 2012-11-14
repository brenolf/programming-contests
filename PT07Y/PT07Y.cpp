#include <stdio.h>
#include <stdlib.h>
#include <vector>;
#define MAX 10005

using namespace std;

vector<int>G[MAX];
int vis[MAX], prt[MAX], nvis = 0;

inline void arc(int v, int w){
	G[v].push_back(w);
}

inline void edge(int v, int w){
	arc(v, w);
	arc(w, v);
}

int hasCycles(int v){
	int i = 0, w = 0;

	vis[v] = 1;
	nvis++;

	for(i = 0; i < G[v].size(); i++){
		w = G[v][i];

		if(!vis[w]){
			prt[w] = v;

			if(hasCycles(w))
				return 1;
		}else if(w != prt[v])
			return 1;
	}

	return 0;
}

int main(){

	int i = 0, N = 0, M = 0, v = 0, w = 0, first = -1;

	scanf("%d %d", &N, &M);

	for(i = 0; i < N; i++){
		vis[i] = 0;
		prt[i] = -1;
	}

	for(i = 0; i < M; i++){
		scanf("%d %d", &v, &w);
		edge(v - 1, w - 1);

		if(first < 0)
			first = v - 1;
	}

	if(first < 0)
		printf("YES");
	else{
		prt[first] = first;

		if(hasCycles(first) || nvis != N)
			printf("NO");
		else
			printf("YES");
	}

	return 0;
}