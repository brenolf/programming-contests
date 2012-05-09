#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 4001

int G[M][M];
char comida[2000][21], a1[21], a2[21];
int l = 0, ind = 0, pos = 0, stack[M], scc[M], vis[M], low[M], seen[M], sccN = 0;

inline void arc(int v, int w){
	int a = G[v][0] + 1, i = 1;

	for(i;i<a;i++)
		if(G[v][i] == w)return;

	G[v][a] = w;
	G[v][0]++;
}

inline int not(int n){
	return n%2==0?n+1:n-1;
}

inline void push(int v){
	seen[v]++;
	stack[pos++] = v;
}

inline int pop(){
	int v = stack[--pos];
	seen[v]++;
	return v;
}

inline int min(int x, int y){
	return x<y?x:y;
}

inline int getI(char s[]){
	int i = 0, e = 0;

	if(s[0] == '!'){
		e = 1;
		s++;
	}

	for(i=0;i<l;i++)
		if(!strcmp(s, comida[i]))break;
	
	if(i == l){
		strcpy(comida[i], s);
		G[2*i][0] = 0;
		G[(2*i)+1][0] = 0;
		l++;
	}
	
	return 2*i + e;
}

void dfs(int v){
	
	int p = G[v][0], i = 1, w = 0, x = 0;
	
	vis[v] = ind;
	low[v] = ind++;
	
	push(v);
	
	for(i;i<=p;i++){
		w = G[v][i];
		
		if(!seen[w]){
			dfs(w);
			low[v] = min(low[v], low[w]);
		}else if(seen[w] == 1)
			low[v] = min(low[v], vis[w]);
	}
	
	if(low[v] == vis[v]){
		sccN++;
		do{
			x = pop();
			scc[x] = sccN;
		}while(x != v);
	}
}

inline void showMe(){
	int i = 0;
	
	for(i;i<l;i++){
		if(scc[2*i] == scc[(2*i)+1]){
			printf("nao\n\n");
			return;
		}
	}
	
	printf("sim\n\n");
}

int main(){
	
	int i = 0, n = 0, k = 0, a = 0, b = 0;
	
	
	while(scanf("%d", &n) != EOF){
		l = 0;
		pos = 0;
		ind = 0;
		sccN = 0;
		
		for(i=0;i<n;i++){
			scanf("%s %s", a1, a2);
			a = getI(a1);
			b = getI(a2);
	
			arc(not(a), b);
			arc(not(b), a);
		}
		
		for(i=0;i<l*2;i++)
			seen[i] = 0;
	
		for(i=0;i<l*2;i++){
			if(!seen[i])dfs(i);
		}
		
		printf("Instancia %d\n", ++k);
		
		showMe();
	}

	return 0;
}
