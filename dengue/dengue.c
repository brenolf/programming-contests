#include <stdio.h>
#define MAX 101

int G[MAX][MAX], ADJ[MAX], P[MAX], Q[MAX], vis[MAX], top = 0, end = 0;

inline void push(int v){
	Q[end++] = v;
}

inline int pop(){
	return Q[top++];
}

inline void edge(int v, int w){
	G[v][w] = 1;
	G[w][v] = 1;

	ADJ[v]++;
	ADJ[w]++;
}

int find(int v){
	return P[v] == v ? v : find(P[v]);
}

inline void unionf(int v, int w){
	v = find(v);
	w = find(w);

	P[v] = w;

	ADJ[w]--;
	ADJ[v]--;
}

int main(){

	int n = 0, i = 0, j = 0, v = 0, w = 0, k = 1, N = 0;

	while(1){
		scanf("%d", &n);

		if(!n)
			break;

		N = n;

		top = 0;
		end = 0;

		for(i = 0; i < n; i++){
			ADJ[i] = 0;
			vis[i] = 0;
			P[i] = i;
			for(j = 0; j < n; j++)
				G[i][j] = 0;
		}

		for(i = 0; i < n - 1; i++){
			scanf("%d %d", &v, &w);
			edge(v - 1, w - 1);
		}

		for(i = 0; i < n; i++)
			if(ADJ[i] == 1){
				push(i);
				vis[i] = 1;
			}

		while(top != end){
			v = pop();
			vis[v] = 2;

			if(!ADJ[v])
				break;

			for(w = 0; w < n; w++){
				if(!G[v][w] || vis[w] == 2)
					continue;

				unionf(v, w);

				if(!vis[w] && ADJ[w] <= 1){
					push(w);
					vis[w] = 1;
				}
			}
		}

		printf("Teste %d\n%d\n\n", k++, find(0) + 1);
	}

	return 0;
}