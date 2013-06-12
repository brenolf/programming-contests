#include <stdio.h>
#define MAX 500000

typedef struct {
	int x, y;
	int depth;
} Pair;

Pair fila[MAX];
int top = 0, bottom = 0;

inline Pair shift(){
	return fila[top++];
}

inline int empty(){
	return (top == bottom);
}

inline void push(int x, int y, int depth){
	if(x < 0 || y < 0 || x >= 8 || y >= 8)
		return;

	Pair p;
	p.x = x;
	p.y = y;
	p.depth = depth;
	
	fila[bottom++] = p;
}

inline void clean(){
	top = bottom = 0;
}

int main(){
		
	char a, b;
	int x, y, r;
	Pair p;
	
	while(scanf("%c%d %c%d", &a, &x, &b, &y) != EOF){
		getchar();
		
		a -= 'a';
		b -= 'a';
		x--;
		y--;
		
		clean();
		push(a, x, 0);
		
		while(!empty()){
			p = shift();
			
			if(p.x == b && p.y == y)
				break;
				
			push(p.x - 2, p.y + 1, p.depth + 1);
			push(p.x - 2, p.y - 1, p.depth + 1);
			push(p.x - 1, p.y + 2, p.depth + 1);
			push(p.x - 1, p.y - 2, p.depth + 1);
			push(p.x + 2, p.y + 1, p.depth + 1);
			push(p.x + 2, p.y - 1, p.depth + 1);
			push(p.x + 1, p.y + 2, p.depth + 1);
			push(p.x + 1, p.y - 2, p.depth + 1);
		}	
		
		a += 'a';
		b += 'a';
		x++;
		y++;
		
		printf("To get from %c%d to %c%d takes %d knight moves.\n", a, x, b, y, p.depth);
	}


	return 0;
}
