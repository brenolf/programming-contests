#include <stdio.h>
#include <string.h>
#define MAX 31

int G[MAX][MAX], adj[MAX], ret[MAX], stack[MAX], M = 0, top = 0, end = 0, n = 0, reti = 0;
char nomes[MAX][20];


inline void clean(){
	int i = 0, j = 0;

	M = 0;
	top = 0;
	end = 0;
	reti = 0;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			G[i][j] = 0;

		adj[i] = 0;
	}
}

inline void push(int v){
	stack[top++] = v;
}

inline int pop(){
	return stack[end++];
}

inline int empty(){
	return top == end;
}

inline void arc(int v, int w){
	G[v][w] = 1;
	adj[w]++;
}

inline void delArc(int v, int w){
	G[v][w] = 0;
	adj[w]--;
}

inline int getIndex(char nome[20]){
	int i = 0;

	for(i = 0; i < n; i++)
		if(!strcmp(nome, nomes[i]))
			return i;

	return 0;
}

int main(){

	int i = 0, j = 0, v = 0, w = 0, a = 0, k = 1;
	char nome[20];

	while(1){
		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		clean();

		for(i = 0; i < n; i++){
			scanf("%s", nomes[i]);
			getchar();
		}

		for(i = 0; i < n; i++){
			scanf("%s", nome);
			getchar();

			v = getIndex(nome);

			scanf("%d", &a);
			getchar();

			for(j = 0; j < a; j++){
				scanf("%s", nome);
				getchar();

				w = getIndex(nome);

				arc(w, v);
				M++;
			}
		}

		for(i = 0; i < n; i++)
			if(!adj[i])
				push(i);

		while(!empty()){
			v = pop();

			ret[reti++] = v;

			for(w = 0; w < n; w++){
				if(!G[v][w])
					continue;

				delArc(v, w);
				M--;

				if(!adj[w])
					push(w);
			}
		}


		printf("Teste %d\n", k++);

		if(M)
			printf("impossivel\n\n");
		else{
			for(i = 0; i < reti; i++)
				printf("%s ", nomes[ret[i]]);
			printf("\n\n");
		}
	}

	return 0;
}