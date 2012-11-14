#include <stdio.h>

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){

	int n = 0, i = 0, j = 0, m = 0, menor = 0, menorI = 0, aux = 0, trilhas[2], pathA = 0, pathB = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%d", &m);
		getchar();

		trilhas[0] = 0;
		trilhas[1] = 0;

		for(j = 0; j < m; j++){
			pathB = pathA;
			scanf("%d", &pathA);
			getchar();

			if(j){
				if(pathA - pathB > 0)
					trilhas[0] += pathA - pathB;
				else
					trilhas[1] += pathB - pathA;
			}
		}

		aux = min(trilhas[0], trilhas[1]);

		if(!i || aux < menor){
			menor = aux;
			menorI = i + 1;
		}
	}

	printf("%d", menorI);

	return 0;
}