#include <stdio.h>
#include <stdlib.h>

inline int max(int a, int b){
	return a > b ? a : b;
}

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	
	int X = 0, Y = 0, U = 0, V = 0;
	int i = 0, n = 0, x = 0, y = 0, u = 0, v = 0, R = 0, k = 1;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		X = -10000;
		Y = 10000;
		U = 10000;
		V = -10000;
		
		R = 0;
		
		for(i = 0; i < n; i++){
			
			scanf("%d %d %d %d", &x, &y, &u, &v);
			
			if(R)
				continue;
			
			if(v >= Y || u <= X || x >= U || y <= V){
				R = 1;
				continue;
			}
			
			X = max(X, x);
			Y = min(Y, y);
			
			U = min(U, u);
			V = max(V, v);
		}
		
		printf("Teste %d\n", k++);
		
		if(R)
			printf("nenhum\n\n");
		else
			printf("%d %d %d %d\n\n", X, Y, U, V);
		
	}

	return 0;
}
