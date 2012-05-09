#include <stdio.h>
#include <stdlib.h>
#define M 100

int fila[M];

inline int getPos(int grau, int max){
	int ct = 0, i = 0;

	for(i = 0; i < max; i++){
		if(fila[i] != 0){
			if(ct++ == grau)
				return i;
		}
	}
	return -1;
}

int main(){
	
	int i = 0, j = 0, p = 0, r = 0, n = 0, b = 0, pos = 0, k = 0, now = 0;
	
	while(1){
		
		scanf("%d %d", &p, &r);
		
		if(!p && !r)
			break;
		
		for(i = 0; i < p; i++)
			scanf("%d", &fila[i]);
		
		for(i = 0; i < r; i++){
			
			scanf("%d%d", &n, &b);
			
			for(j = 0; j < n; j++){
				scanf("%d", &now);
				
				if(now != b)
					fila[getPos(j, p)] = -1;
			}
			
			for(j = 0; j < p; j++){
				if(fila[j] < 0)
					fila[j] = 0;
			}
			
		}
		
		for(i = 0; i < p; i++){
			if(fila[i] != 0){
				printf("Teste %d\n%d\n\n", ++k, fila[i]);
				break;
			}
		}
	}

	return 0;
}
