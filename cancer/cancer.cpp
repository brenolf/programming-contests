#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

int counter = 0;

inline int max(int a, int b){
	return a > b ? a : b;
}

typedef struct {
	int a, b;
} Pair;

typedef struct {
	int vis[MAX], degree[MAX], adj[MAX][MAX], prt[MAX], dist[MAX], height;
} Graph;

typedef struct {
	int label, G, v;
	vector<int> children;
} Vertex;

int N = 0, degree[MAX];
Graph G, H;
queue<int> fila;
vector<Vertex> L[MAX];

bool ord(int a, int b){
	return a < b;
}

bool cmp(Vertex a, Vertex b){
	if(a.children.size() != b.children.size())
		return a.children.size() < b.children.size();

	for(int i = 0; i < a.children.size(); i++){
		if(a.children[i] == b.children[i])
			continue;

		return a.children[i] < b.children[i];
	}
}

bool equals(Vertex i, Vertex j){
	vector<int> a = i.children, b = j.children;

	if(a.size() != b.size())
		return false;

	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[i])
			continue;

		return false;
	}

	return true;
}

void printVertex(Vertex i){
	printf("{");
	for(int v = 0; v < i.children.size(); v++)
		printf("%d, ", i.children[v]);
	printf("}, ");
}

int isomorphic(int r1, int r2){
	if(G.height != H.height)
		return 0;

	int h = G.height, l = 0;
	int i = 0, j = 0, v = 0, w = 0;
	int pos[2][N], c = 0;
	vector<Vertex> aux;
	Vertex vx;
	map< vector<int> , int> M;

	for(i = 0; i < h; i++)
		L[i].clear();

	for(i = 0; i < h; i++){
		for(w = 0; w < N; w++)
			if(G.dist[w] == i){
				Vertex v;
				v.G = 0;
				v.v = w;
				v.label = 0;
				L[i].push_back(v);
				pos[0][w] = L[i].size() - 1;
			}

		for(w = 0; w < N; w++)
			if(H.dist[w] == i){
				Vertex v;
				v.G = 1;
				v.v = w;
				v.label = 0;
				L[i].push_back(v);
				pos[1][w] = L[i].size() - 1;
			}
	}

	for(i = h - 1; i > 0; i--){
		l = i - 1;

		for(j = 0; j < L[i].size(); j++){
			vx = L[i][j];

			w = !vx.G ? G.prt[vx.v] : H.prt[vx.v];
			
			l = i - 1;
			int posPai = pos[vx.G][w];

			L[l][posPai].children.push_back(vx.label);
			sort(L[l][posPai].children.begin(), L[l][posPai].children.end(), ord);
		}
		
		aux = L[l];

		sort(aux.begin(), aux.end(), cmp);

		/*
		printf("[");

		for(j = 0; j < aux.size(); j++){
			printVertex(aux[j]);
		}

		printf("]");
		*/

		c = 1;
		M.clear();

		M[aux[0].children] = c;

		for(j = 1; j < aux.size(); j++){
			if(!equals(aux[j], aux[j - 1]))
				c++;
			
			M[aux[j].children] = c;
		}

		for(v = 0; v < L[l].size(); v++)
			L[l][v].label = M[L[l][v].children];
	}

	/*
	r1 = 0;
	for(i = 0; i < L[r1].size(); i++){
		printf("{");
		for(j = 0; j < L[r1][i].children.size(); j++){
			printf("%d ", L[r1][i].children[j]);
		}
		printf("}\n");
	}*/

	r1 = L[0][ pos[0][r1] ].label;
	r2 = L[0][ pos[1][r2] ].label;

	//printf("{%d %d}\n", r1, r2);

	return r1 == r2;
}

void bfs(Graph* G, int root){
	(*G).dist[root] = 0;
	(*G).vis[root] = 1;
	(*G).prt[root] = root;

	fila.push(root);

	int v = 0, w = 0, hasEdge = 0;

	while(!fila.empty()){
		w = fila.front();
		fila.pop();

		for(v = 0; v < N; v++){
			if((*G).adj[w][v] && !(*G).vis[v]){
				fila.push(v);

				(*G).dist[v] = (*G).dist[w] + 1;
				(*G).vis[v] = 1;
				(*G).prt[v] = w;

				(*G).height = max((*G).height, (*G).dist[v] + 1);
			}
		}
	}
}

Pair centre(Graph* G){
	while(!fila.empty())
		fila.pop();

	queue<int> aux;

	int v = 0, w = 0, hasEdge = 0, vertices = N;
	Pair ret;

	ret.a = -1;
	ret.b = -1;

	for(v = 0; v < N; v++){
		degree[v] = (*G).degree[v];

		if(degree[v] == 1){
			fila.push(v);
			degree[v]--;
		}else if(!degree[v])
			vertices--;
	}

	while(vertices > 2){
		while(!fila.empty()){
			v = fila.front();
			fila.pop();

			vertices--;

			for(w = 0; w < N; w++)
				if((*G).adj[v][w] && --degree[w] == 1)
						aux.push(w);
		}

		while(!aux.empty()){
			fila.push(aux.front());
			aux.pop();
		}
	}

	ret.a = fila.front();
	fila.pop();

	if(!fila.empty()){
		ret.b = fila.front();
		fila.pop();
	}

	return ret;
}

inline void arc(Graph* G, int v, int w){
	(*G).adj[v][w] = 1;
	(*G).degree[v]++;
}

inline void edge(Graph* G, int v, int w){
	arc(G, v, w);
	arc(G, w, v);
}

void clear(){
	int i = 0, j = 0;

	G.height = H.height = 0;

	for(i = 0; i < N; i++){
		G.prt[i] = i;
		H.prt[i] = i;

		G.dist[i] = 0;
		H.dist[i] = 0;

		G.vis[i] = 0;
		H.vis[i] = 0;

		G.degree[i] = 0;
		H.degree[i] = 0;

		for(j = 0; j < N; j++){
			G.adj[i][j] = 0;
			H.adj[i][j] = 0;
		}
	}
}

int main(){

	int i = 0, j = 0, v = 0, w = 0;
	Pair r1, r2, aux;

	while(scanf("%d", &N) != EOF){

		clear();

		for(i = 0; i < N - 1; i++){
			scanf("%d %d", &v, &w);
			edge(&G, v - 1, w - 1);
		}

		for(i = 0; i < N - 1; i++){
			scanf("%d %d", &v, &w);
			edge(&H, v - 1, w - 1);
		}

		r1 = centre(&G);
		r2 = centre(&H);

		bfs(&G, r1.a);
		bfs(&H, r2.a);

		if(isomorphic(r1.a, r2.a))
			printf("S\n");
		else if(r1.b == -1 && r2.b == -1)
				printf("N\n");
		else{
			if(r2.b != -1){
				for(i = 0; i < N; i++){
					H.dist[i] = 0;
					H.vis[i] = 0;
				}

				H.height = 0;

				bfs(&H, r2.b);
				printf(isomorphic(r1.a, r2.b) ? "S\n" : "N\n");
			}else{
				for(i = 0; i < N; i++){
					G.dist[i] = 0;
					G.vis[i] = 0;
				}

				G.height = 0;

				bfs(&G, r1.b);
				printf(isomorphic(r1.b, r2.a) ? "S\n" : "N\n");
			}
		}

	}

	return 0;
}