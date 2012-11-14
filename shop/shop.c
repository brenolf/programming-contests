#include <stdio.h>
#define MAX 26
#define INFINITY 99999

int N = 0, m = 0;
char G[MAX][MAX];
int dis[MAX][MAX], vis[MAX][MAX], 
	Sx = 0, Sy = 0, Dx = 0, Dy = 0;

void updateDistances(int Ux, int Uy){
	int v = 0, cost = 0;
	int x[] = {1, -1, 0, 0}, y[] = {0, 0, -1, 1}, nx = 0, ny = 0;

	for(v = 0; v < 4; v++){
		nx = Ux + x[v];
		ny = Uy + y[v];

		if(nx < 0 || nx >= m || ny < 0 || ny >= N || vis[nx][ny] || G[nx][ny] == 'X')
			continue;

		cost = G[nx][ny] == 'D' ? 0 : (G[nx][ny] - '0');

		if(dis[nx][ny] > dis[Ux][Uy] + cost)
			dis[nx][ny] = dis[Ux][Uy] + cost;
	}
}

void dijkstra(){
	int v = 0, w = 0, Ux = 0, Uy = 0, menor = 0;

	dis[Sx][Sy] = 0;

	while(1){

		menor = INFINITY;

		for(v = 0; v < m; v++)
			for(w = 0; w < N; w++)
				if(!vis[v][w] && dis[v][w] < menor){
					Ux = v;
					Uy = w;
					menor = dis[Ux][Uy];
				}

		if(menor == INFINITY || (Ux == Dx && Uy == Dy))
			break;

		vis[Ux][Uy] = 1;

		updateDistances(Ux, Uy);
	}

}

int main(){

	int i = 0, j = 0;
	char c;

	while(1){
		scanf("%d %d", &N, &m);
		getchar();

		if(!N && !m)
			break;

		for(i = 0; i < m; i++)
			for(j = 0; j < N; j++){
				vis[i][j] = 0;
				dis[i][j] = INFINITY;
			}

		for(i = 0; i < m; i++){
			for(j = 0; j < N; j++){
				scanf("%c", &c);

				if(c == 'S'){
					Sx = i;
					Sy = j;
				}else if(c == 'D'){
					Dx = i;
					Dy = j;
				}
				
				G[i][j] = c;
			}
			getchar();
		}

		dijkstra();

		printf("%d\n", dis[Dx][Dy]);
	}

	return 0;
}
