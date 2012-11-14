/*
 * Treinamento Maratona 2012 - Problema A - Linha de Transmissão
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */

#include <stdio.h>
#define MAX 100001

int main(){
	int n = 0, t = 0, i = 0, ini = 0, m[MAX];
	unsigned long long ac = 0, R = 0;

	while(1){
		scanf("%d %d", &n, &t);

		if(!n && !t)
			break;

		ac = 1;

		ini = 0;
		R = -1;

		for(i = 0; i < n; i++){
			scanf("%1d", &m[i]);

			if(i < t){
				ac *= m[i];
				R = ac;
			}else{
				if(ini > n - t)
					break;

				ac = (ac / m[ini++]) * m[i];

				if(ac > R)
					R = ac;
			}
		}

		getchar();

		printf("%llu\n", R);
	}

	return 0;
}
