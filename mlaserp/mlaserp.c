#include <stdio.h>
#include <stdlib.h>
#define M 100

typedef struct {
	int x, y, lx, ly, e;
} Movimento;

char G[M][M];
int H[M][M], ini = 0, fim = 0, X = -1, Y = -1, n = 0, m = 0, vis[M][M], ord = 0;
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

inline Movimento pair(int x, int y){
	Movimento m;
	m.x = x;
	m.y = y;
	m.lx = 0;
	m.ly = 0;
	m.e = 0;
	return m;	
}

inline Movimento new(int x, int y, int lx, int ly, int e){
	Movimento m;
	m.x = x;
	m.y = y;
	m.lx = lx;
	m.ly = ly;
	m.e = e;
	return m;
}

int bfs(){
	push(new(X, Y, 0, 0, 0));
	int x = 0, y = 0, p = 0, lx = 0, ly = 0, i = 0, e = 0, nx = 0, ny = 0, plus = 0;
	Movimento viz[4] = {pair(0, 1), pair(0, -1), pair(1, 0), pair(-1, 0)};
	
	while(!empty()){
		Movimento atual = pop();
		
		x = atual.x;
		y = atual.y;
		lx = atual.lx;
		ly = atual.ly;
		e = atual.e;
		
		H[x][y] = e;
		
		if(G[x][y] == 'C')
			return e;

		vis[x][y] = 2;

		for(i = 0; i < 4; i++){
			nx = x + viz[i].x;
			ny = y + viz[i].y;
			
			if((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && !vis[nx][ny] && G[nx][ny] != '*'){
				
				plus = e;
				
				if((x != X || y != Y) && ((!lx && viz[i].x) || (lx && !viz[i].x)))
					plus++;

				push(new(nx, ny, viz[i].x, viz[i].y, plus));
				vis[nx][ny] = 1;
			}
		}
	}
	
	return -1;
}

int main(){
	
	int i = 0, j = 0, read = 0;
	
	scanf("%d %d", &n, &m);
	getchar();

	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%c", &G[i][j]);
			//printf("%c\t", G[i][j]);
			
			vis[i][j] = 0;
			H[i][j] = -1;
			
			if(G[i][j] == 'C' && X < 0 && Y < 0){
				X = i;
				Y = j;
				G[i][j] = '.';
			}
		}
		//printf("\n");
		getchar();
	}
	
	printf("%d", bfs());

	/*for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
				printf("%d\t", H[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}
