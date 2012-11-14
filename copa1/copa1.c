#include <stdio.h>

int main(){

	int i = 0, m = 0, n = 0;
	char jogos[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

	for(i = 0; i < 8; i++){
		scanf("%d %d", &m, &n);
		if(n > m)
			jogos[2 * i] = jogos[2 * i + 1];
	}

	for(i = 0; i < 4; i++){
		scanf("%d %d", &m, &n);
		if(n > m)
			jogos[4 * i] = jogos[4 * i + 2];
	}

	for(i = 0; i < 2; i++){
		scanf("%d %d", &m, &n);
		if(n > m)
			jogos[8 * i] = jogos[8 * i + 4];
	}

	scanf("%d %d", &m, &n);
	
	if(n > m)
		jogos[0] = jogos[8];

	printf("%c", jogos[0]);

	return 0;
}