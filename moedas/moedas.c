#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int cmp(const void *pa, const void *pb){
	return *(int*)pb - *(int*)pa;
}

int main(){
	
	int m = 0, n = 0, qt = 0, i = 0;
	int moedas[MAX];
	
	while(1){
		scanf("%d %d", &m, &n);
		getchar();
		
		if(!m)
			break;
			
		for(i = 0; i < n; i++){
			scanf("%d", &moedas[i]);
			getchar();
		}
		
		qsort(moedas, n, sizeof(int), cmp);
		
		i = 0;
		qt = 0;
		
		while(m){
			if(i >= n){
				qt--;
				m += moedas[i - 2];
				i--;
			}
		
			if(moedas[i] <= m){
				m = m % moedas[i];
				qt += m / moedas[i];
			}
			
			i++;
		}
		
		printf("%d\n", qt);
	}

	return 0;
}
