#include <stdio.h>
#define MAX 100001

typedef struct {
	int x, y;
} Pair;

Pair vet[MAX], lowest;

int main(){
	
	int i = 0, T = 0, N = 0;
	
	scanf("%d", &T);
	
	getchar();
	getchar();

	while(T--){
		scanf("%d", &N);
		getchar();
		
		for(i = 0; i < N; i++){
			scanf("%d %d", vet[i].x, vet[i].y);
			getchar();
			
			if(!i || lowest.y > vet[i].y || (lowest.y == vet[i].y && lowest.x > vet[i].x))
				lowest = vet[i];
		}
		
		
	}

	return 0;
}
