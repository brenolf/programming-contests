#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char N, S[20];
	int vis;
} Autor;

Autor autores[101];
int A = 0, nAut = 0, G[101][101], prt[101];

inline void edge(int a, int b){
	G[a][b] = 1;
	G[b][a] = 1;
}

inline void read(){
	char N, S[20], end;
	int i = 0, j = 0, EX = 0, last = 0, elem = 0, vertex[101], vI = 0;
	
	do{
		scanf("%c. %s", &N, S);
	
		last = strlen(S) - 1;
		end = S[last];
		S[last] = '\0';
	
		EX = 1;
		elem = 0;
	
		for(i = 0; i < nAut; i++)
			if(autores[i].N == N && !strcmp(autores[i].S, S)){
				EX = 0;
				elem = i;
				break;
			}
		
		if(EX){
			sscanf(S, "%s", autores[nAut].S);
			autores[nAut].N = N;
			autores[nAut].vis = -1;
			
			elem = nAut;
			
			nAut++;
		}
		
		getchar();
		
		vertex[vI++] = elem;
		
	}while(end != '.');
	
	for(i = 0; i < vI; i++)
		for(j = 0; j < vI; j++)
			edge(vertex[i], vertex[j]);
}

void bfs(){
	int fila[101], ini = 0, fim = 0;
	int v = 0, w = 0;
	
	fila[fim++] = 0;
	
	while(ini != fim){
		v = fila[ini++];
		
		autores[v].vis = autores[prt[v]].vis + 1;
		
		for(w = 0; w < nAut; w++)
			if(G[v][w] && prt[w] < 0){
				prt[w] = v;
				fila[fim++] = w;
			}
	}
}

int cmp(const void *a, const void *b){
	Autor *A = (Autor*)a, *B = (Autor*)b;
	
	int str = strcmp(A->S, B->S), ch = A->N - B->N;
	
	if(str)
		return str;
	return ch;
}

int main(){
	int i = 0, j = 0, k = 1;
	char num[5] = "0", inf[] = "infinito";
	
	while(1){
		
		scanf("%d", &A);
		
		getchar();
		
		if(!A)
			break;
			
		autores[0].N = 'P';
		sscanf("Erdos", "%s", autores[0].S);
			
		nAut = 1;
	
		for(i = 0; i < 100; i++){
			prt[i] = -1;
			autores[i].vis = -1;
			
			if(i)
				autores[i].N = '\0';
			
			for(j = 0; j < 100; j++)
				G[i][j] = 0;
		}
	
		prt[0] = 0;
	
		for(i = 0; i < A; i++)
			read();
	
		bfs();
	
		qsort(autores, nAut, sizeof(Autor), cmp);
	
		printf("Teste %d\n", k++);
	
		for(i = 0; i < nAut; i++){
			if(autores[i].vis < 0)
				printf("%c. %s: infinito\n", autores[i].N, autores[i].S);
			else if(autores[i].vis > 0)
				printf("%c. %s: %d\n", autores[i].N, autores[i].S, autores[i].vis);
		}		
		
		printf("\n");
	}

	return 0;
}