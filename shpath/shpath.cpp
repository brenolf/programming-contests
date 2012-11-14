#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define MAX 10001
#define INFINITY 9999999

using namespace std;

typedef vector< pair<int, int> > Graph;

char cities[MAX][20];
int N = 0;
Graph *G, *dis;

inline void arc(int v, int w, int c){
	G[v].push_back(make_pair(w, c));
}

inline void edge(int v, int w, int c){
	arc(v, w, c);
	arc(w, v, c);
}

inline int getCity(){
	int i = 0;
	char name[20];

	scanf("%s", name);
	getchar();

	for(i = 0; i < N; i++)
		if(!strcmp(name, cities[i]))
			return i;

	return 0;
}

inline int min(int a, int b){
	return a < b ? a : b;
}

inline int get(int v, int w){
	int i = 0;

	if(v == w)
		return 0;

	for(i = 0; i < G[v].size(); i++)
		if(G[v][i].first == w)
			return G[v][i].second;

	return INFINITY;
}

void FloydWarshall(){
	int v = 0, w = 0, k = 0;

	for(v = 0; v < N; v++)
		for(w = 0; w < N; w++)
			dis[v].push_back(make_pair(w, get(v, w)));


	for(k = 0; k < N; k++)
		for(v = 0; v < N; v++)
			for(w = 0; w < N; w++)
				dis[v][w].second = min(dis[v][w].second, dis[v][k].second + dis[k][w].second);
}

int main(){
	int s = 0, p = 0, nr = 0, c = 0, r = 0,
		v = 0, w = 0;

	scanf("%d", &s);
	getchar();

	while(s--){
		scanf("%d", &N);
		getchar();

		G = new Graph[N];
		dis = new Graph[N];

		for(v = 0; v < N; v++){
			scanf("%s", cities[v]);
			getchar();

			scanf("%d", &p);
			getchar();

			while(p--){
				scanf("%d", &nr);
				getchar();

				scanf("%d", &c);
				getchar();

				edge(v, nr - 1, c);
			}
		}

		FloydWarshall();

		scanf("%d", &r);

		while(r--){
			v = getCity();
			w = getCity();

			printf("%d\n", dis[v][w].second);
		}

		delete[] G;
		delete[] dis;
	}

	return 0;
}
