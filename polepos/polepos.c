#include <stdio.h>
#define MAX 1001

typedef struct {
	int n, pos;
} Carro;

int main(){
	
	int n = 0, i = 0;
	Carro grid[MAX];
	
	
	while(1){
		
		scanf("%d", &n);
		
		if(!n)
			break;
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &c, &p);
			
			grid[i].n = c;
			grid[i].pos = p;
		}
		
	}

	return 0;
}
