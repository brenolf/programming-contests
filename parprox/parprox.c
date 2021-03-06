#include <stdio.h>
#include <math.h>
#define MAX 1001

typedef struct {
	double x, y;
} Pair;

Pair pares[MAX];

double menor(int n){
	int i = 0, j = 0, k = 1;
	
	double menor = 0, aux = 0, X = 0, Y = 0;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
		
			if(i == j)
				continue;
		
			X = (pares[i].x - pares[j].x);
			Y = (pares[i].y - pares[j].y);
		
			aux = X * X + Y * Y;
			
			if(aux < menor || k){
				menor = aux;
				k = 0;
			}
		}
	}
	
	return sqrt(menor);
}

int main(){
	int n = 0, i = 0, a = 0, b = 0;
	
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		
		pares[i].x = a;
		pares[i].y = b;
	}
	
	printf("%.3lf", menor(n));

	return 0;
}
