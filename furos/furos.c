#include <stdio.h>
#include <math.h>
#define MAX 1001
#define INFTY 999999

typedef struct {
	double x, y;
} Pair;

inline double max(double a, double b){
	return a > b ? a : b;
}

inline double min(double a, double b){
	return a < b ? a : b;
}

inline double raiz(int a){
	return floor(sqrt(a));
}

int main(){
	Pair M[MAX];
	int n = 0, i = 0, j = 0, k = 1;
	double x = 0, y = 0, dist = 0, maior = 0, menor = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
		
		for(i = 0; i < n; i++){
			scanf("%lf %lf", &x, &y);
			
			M[i].x = x;
			M[i].y = y;
		};
		
		menor = INFTY;
		
		for(i = 0; i < n; i++){
			maior = -INFTY;
		
			for(j = 0; j < n; j++){
				if(j == i)
					continue;
			
				dist = raiz((M[j].x - M[i].x) * (M[j].x - M[i].x) + (M[j].y - M[i].y) * (M[j].y - M[i].y));
				maior = max(maior, dist);
			}
			
			menor = min(menor, maior);
		}
		
		menor += 2.5;
		
		printf("Teste %d\n%d\n\n", k++, (int) ((menor * 2) + 1));
	}
	
	return 0;
}
