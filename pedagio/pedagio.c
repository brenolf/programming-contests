#include <stdio.h>
#include <stdlib.h>
#define N 50

typedef int** Graph;

typedef struct node{
	int w, o;
	struct node *next;
} Node;

typedef Node* Queue;

Queue f = NULL;

void push(int v){
	if(f==NULL){
		f = (Queue) malloc(sizeof(Queue));
		f -> w = v;
		f -> next = NULL;
	}else{
		Queue p, n = (Queue) malloc(sizeof(Queue));
		
		for(p=f;p->next!=NULL;p=p->next);
		
		n -> w = v;
		n -> next = NULL;
		
		p -> next = n;
	}
}

int pop(){
	Queue n = f;
	int w = n -> w;
	
	f = f -> next;
	
	free(n);
	
	return w;
}

int hasItems(){
	return f==NULL?0:1;
}

int main(){
	
	int i = 0, j = 0, c = 0, e = 0, l = 0, p = 0, x = 0, y = 0, w = 0, k = 0, vis[N];
	
	Queue a;
	
	Graph G = (Graph) malloc(sizeof(int*) * N);
	
	for(i=0;i<N;i++){
		G[i] = (int*) calloc(N, sizeof(int));
		vis[i] = 0;
	}
	
	while(1){
		scanf("%d %d %d %d", &c, &e, &l, &p);
		
		if(!c && !e && !l && !p)break;
		
		l--;
		p++;
		
		for(i=0;i<c;i++){
			vis[i] = 0;
			for(j=0;j<c;j++)G[i][j] = 0;
		}

		for(i=0;i<e;i++){
			scanf("%d %d", &x, &y);
			
			x--;
			y--;
			
			G[x][y] = 1;
			G[y][x] = 1;
		}
		
		push(l);
		vis[l] = 1;
		
		while(hasItems()){		
			w = pop();
			
			for(i=0;i<c;i++){
				if(G[w][i] && vis[i] == 0){
					vis[i] = vis[w] + 1;
					
					if(vis[i] != p)push(i);
				}
			}
		}
		
		printf("Teste %d\n", ++k);
		
		for(i=0;i<c;i++){
			if(vis[i]>0 && i!=l)printf("%d ", i+1);
		}
		
		printf("\n\n");
	}

	for(i=0;i<N;i++)
		free(G[i]);
		
	free(G);
	
	return 0;
}
