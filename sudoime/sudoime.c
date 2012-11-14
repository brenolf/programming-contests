#include <stdio.h>

int m[9][9], nove[10];

inline int clean(){
	int i = 0, r = 0;

	for(i = 1; i < 10; i++){
		r += nove[i];
		nove[i] = 0;
	}

	return r == 9 ? 1 : 0;
}

inline int valid(){
	int i = 0, j = 0, k = 0;

	clean();

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++)
			nove[m[i][j]] = 1;

		if(!clean())
			return 0;
	}

	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++)
			nove[m[j][i]] = 1;

		if(!clean())
			return 0;
	}

	for(i = 0; i < 9; i += 3){
		for(j = 0; j < 9; j += 3){
			for(k = 0; k < 9; k++)
				nove[m[i + k / 3][j + k % 3]] = 1;

			if(!clean())
				return 0;
		}
	}

	return 1;
}

int main(){

	int i = 0, j = 0, n = 0, k = 1;

	nove[0] = 0;

	scanf("%d", &n);
	getchar();

	while(n--){
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				scanf("%d", &m[i][j]);
				getchar();
			}
		}

		if(valid())
			printf("Instancia %d\nSIM\n\n", k++);
		else
			printf("Instancia %d\nNAO\n\n", k++);
	}

	return 0;
}