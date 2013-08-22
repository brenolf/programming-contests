// UVA The Dragon of Loowater
#include <stdio.h>
#include <stdlib.h>
#define MAX 20001

int cmp(const void *a, const void *b){
	int *na = (int*) a, *nb = (int*) b;
	return *na - *nb;
}

int main(){

	int n, m, i, j, killed, cost;
	int heads[MAX], knights[MAX];

	while(1){
		scanf("%d %d", &n, &m);

		if(!n && !m)
			break;

		for(i = 0; i < n; i++)
			scanf("%d", &heads[i]);

		for(i = 0; i < m; i++)
			scanf("%d", &knights[i]);

		if(m < n){
			printf("Loowater is doomed!\n");
			continue;
		}

		qsort(heads, n, sizeof(int), cmp);
		qsort(knights, m, sizeof(int), cmp);

		j = killed = cost = 0;

		for(i = 0; i < n; i++){
			for(; j < m && knights[j] < heads[i]; j++);

			if(j < m){
				cost += knights[j++];
				killed++;
			}
		}

		if(killed < n)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", cost);
	}

	return 0;
}