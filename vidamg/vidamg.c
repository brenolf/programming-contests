#include <stdio.h>
#define MAX 2100000
#define FLOOR 1048576

typedef struct {
	 int x, y;
} Position;

int M[MAX][MAX], top = 0, end = 0;
Position queue[MAX];

inline void push(int x, int y){
	Position p;
	p.x = x;
	p.y = y;

	queue[end++] = p;
}

inline Position pop(){
	return queue[top++];
}

inline int empty(){
	return top == end;
}

inline int neighbours(Position p){
	int x = p.x, y = p.y, n = 0;
	if(x > 0){
		if(M[x - 1][y])
			n++;
	}

	if(x < MAX - 1){
		if(M[x + 1][y])
			n++;
	}

	if(y > 0){
		if(M[x][y - 1])
			n++;
		if(x > 0 && M[x - 1][y - 1])
			n++;
		if(x < MAX - 1 && M[x + 1][y - 1])
			n++;
	}

	if(y < MAX - 1){
		if(M[x][y + 1])
			n++;
		if(x > 0 && M[x - 1][y + 1])
			n++;
		if(x < MAX - 1 && M[x + 1][y + 1])
			n++;
	}

	return n;
}

int main(){

	int n = 0, l = 0, c = 0, i = 0, j = 0, k = 0, N = 0;
	Position p;

	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			M[i][j] = 0;

	while(1){
		scanf("%d", &n);

		if(!n)
			break;

		while(n--){
			scanf("%d %d", &l, &c);
			l += FLOOR;
			c += FLOOR;
			push(l, c);
			M[l][c] = 1;
		}

		scanf("%d", &k);

		while(k--){
			while(!empty()){
				p = pop();

				N = neighbours(p);

				if(N < 2 || N > 3){
					
				}
			}
		}
	}

	return 0;
}