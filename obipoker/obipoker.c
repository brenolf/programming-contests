#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(){

	int n = 0, i = 0, j = 0, aux = 0, k = 1, pts = 0, c[5];

	scanf("%d", &n);
	getchar();

	while(n--){
		for(j = 0; j < 5; j++){
			scanf("%d", &c[j]);
			getchar();
		}

		qsort(c, 5, sizeof(int), cmp);

		aux = 0;

		// cartas diferentes
		pts = 0;

		// em sequencia
		for(i = 1; i < 5; i++)
			if(c[i] == c[i - 1] + 1)
				aux++;

		if(aux == 4)
			pts = c[0] + 200;

		// quadra
		else if((c[1] == c[2] && c[2] == c[3]) && (c[0] == c[1] || c[3] == c[4]))
			pts = c[1] + 180;

		// trinca + duo
		else if(c[0] == c[1] && c[3] == c[4] && (c[2] == c[3] || c[2] == c[1]))
			pts = c[2] + 160;

		// trinca
		else if((c[0] == c[1] && c[1] == c[2]) || (c[1] == c[2] && c[3] == c[2]) || (c[3] == c[4] && c[3] == c[2]))
			pts = c[2] + 140;

		// duas duplas
		else if((c[0] == c[1] && c[2] == c[3]) || (c[1] == c[2] && c[3] == c[4]) || (c[0] == c[1] && c[3] == c[4]))
			pts = 3 * c[3] + 2 * c[1] + 20;

		// uma dupla
		else if(c[0] == c[1] || c[1] == c[2] || c[2] == c[3] || c[3] == c[4])
			pts = (c[0] == c[1]) ? c[0] : ((c[1] == c[2]) ? c[1] : ((c[2] == c[3]) ? c[2] : c[3]));

		printf("Teste %d\n%d\n\n", k++, pts);
	}

	return 0;
}