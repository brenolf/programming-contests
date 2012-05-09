#include <stdio.h>
#include <stdlib.h>
#define M 51

int p[M], v[M];

inline int max(int a, int b){
	return a > b ? a : b;
}

int maior(int i, int w){
	if(!i || !w)
		return 0;
		
	if(p[i] > w)
		return maior(i - 1, w);
	
	return max(maior(i - 1, w), maior(i - 1, w - p[i]) + v[i]);
}

int main(){
	
	int c = 0, f = 0, i = 0, k = 1;
	
	while(1){
		scanf("%d %d", &c, &f);
		
		if(!c && !f)
			break;

		for(i = 0; i < f; i++)
			scanf("%d %d", &p[i], &v[i]);

		printf("Teste %d\n%d\n\n", k++, maior(f - 1, c));
	}
	
	return 0;
}
