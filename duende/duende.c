#include <stdio.h>
#include <stdlib.h>
#define M 10

typedef struct {
	int x, y, p;
} Movimento;

int G[M][M], vis[M][M], ini = 0, fim = 0, X = 0, Y = 0, n = 0, m = 0;
Movimento queue[(M * M) + 1];

inline void push(Movimento m){
	queue[fim++] = m;
}

inline Movimento pop(){
	return queue[ini++];
}

inline int empty(){
	return ini == fim;
}

inline Movimento new(int x, int y, int p){
	Movimento m;
	m.x = x;
	m.y = y;
	m.p = p;
	return m;
}

int bfs(){
	push(new(X, Y, 0));
	int x = 0, y = 0, p = 0, i = 0, nx = 0, ny = 0;
	Movimento viz[4] = {new(1, 0, 0), new(-1, 0, 0), new(0, 1, 0), new(0, -1, 0)};
	
	while(!empty()){
		Movimento atual = pop();
		
		x = atual.x;
		y = atual.y;
		p = atual.p;
		
		if(G[x][y] == 0)
			return p;

		vis[x][y] = 2;

		for(i = 0; i < 4; i++){
			nx = x + viz[i].x;
			ny = y + viz[i].y;
			
			if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && !vis[nx][ny] && G[nx][ny] != 2){
				push(new(nx, ny, p + 1));
				vis[nx][ny] = 1;
			}
		}
	}
	
	return -1;
}

int main(){
	
	int i = 0, j = 0, read = 0;
	
	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &G[i][j]);
			
			vis[i][j] = 0;
			
			if(G[i][j] == 3){
				X = i;
				Y = j;
			}
		}
	}
	
	printf("%d\n", bfs());

	return 0;
}
