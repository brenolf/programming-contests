#include <stdio.h>
#define MAX 1001

int G[MAX][MAX], I[MAX][MAX], vis[MAX], scc[MAX], in[MAX], out[MAX], sccN = 0, N = 0;
int stack[MAX], stackAux[MAX], top = 0;

// Stack

inline void push(int n){
	stack[top++] = n;
}

inline int pop(){
	return stack[--top];
}

inline int empty(){
	return top == 0;
}

inline void restack(){
	int m = top, w = 0;
	top = 0;

	for(w = 0; w < m; w++){
		if(!vis[stack[w]])
			push(stack[w]);
	}	
}

// End Stack

inline void clear(){
	int v = 0, w = 0;

	for(v = 0; v < N; v++){
		in[v] = 0;
		out[v] = 0;

		for(w = 0; w < N; w++){
			G[v][w] = 0;
			I[v][w] = 0;
		}
	}
}

inline void arc(int v, int w){
	G[v][w] = 1;
	I[w][v] = 1;
}

inline void edge(int v, int w){
	arc(v, w);
	arc(w, v);
}

void dfs(char graph, int v){
	vis[v] = 1;

	int w = 0, hasEdge = 0;

	for(w = 0; w < N; w++){

		hasEdge = (graph == 'G') ? G[v][w] : I[v][w];

		if(hasEdge && !vis[w])
			dfs(graph, w);
	}

	if(graph == 'I')
		scc[v] = sccN;
	else
		push(v);
}

int kosaraju(){

	int v = 0;

	for(v = 0; v < N; v++){
		scc[v] = -1;
		vis[v] = 0;
	}
	
	for(v = 0; v < N; v++){
		if(!vis[v])
			dfs('G', v);
	}

	for(v = 0; v < N; v++)
		vis[v] = 0;

	sccN = 0;

	while(!empty()){
		v = pop();

		dfs('I', v);

		restack();

		sccN++;
	}

	return (sccN == 1);
}

int main(){

	int m = 0, i = 0,
		v = 0, w = 0, t = 0,
		R = 0;

	char resps[] = {'1', '2', '*'};

	while(scanf("%d %d", &N, &m) != EOF){

		clear();

		for(i = 0; i < m; i++){
			scanf("%d %d %d", &v, &w, &t);

			v--;
			w--;

			if(i){
				if(t == 1)
					arc(v, w);
				else
					edge(v, w);				
			}
		}

		if(kosaraju())
			printf("-\n");
		else{

			for(v = 0; v < N; v++){
				for(w = 0; w < N; w++){
					if(G[v][w] && scc[v] != scc[w]){
						out[scc[v]]++;
						in[scc[w]]++;
					}
				}
			}

			for(i = 0; i < sccN; i++){
				if(in[i] >= 1 && out[i] >= 1)
					continue;

				if(!in[i] && !out[i])
					R = 2;
				else if(in[i] > 1 || out[i] > 1)
					R = 0;
				else
					R = 1;

				break;
			}

			printf("%c\n", resps[R]);
		}

	}

	return 0;
}
