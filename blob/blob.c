#include <stdio.h>

int m[26][26], col, lin;

void rec(int i, int j, int n, int *count){
	if(i < 0 || j < 0 || i > lin || j > col || m[i][j] != 1)
		return;

	(*count)++;
	m[i][j] = n;

	rec(i - 1, j, n, count);
	rec(i + 1, j, n, count);
	rec(i, j + 1, n, count);
	rec(i, j - 1, n, count);
	rec(i - 1, j - 1, n, count);
	rec(i - 1, j + 1, n, count);
	rec(i + 1, j - 1, n, count);
	rec(i + 1, j + 1, n, count);
}

int main(){

	int t = 0, i, j, cor, maior, aux;
	char c;

	scanf("%d", &t);
	getchar();
	getchar();

	while(t--){
		col = 0;
		lin = 0;
		c = ' ';

		while(c != '\n'){
			scanf("%c", &c);
			m[0][col++] = c - '0';
		}

		col--;
		scanf("%c", &c);

		while(c != '\n'){
			lin++;
			i = 0;

			m[lin][i++] = c - '0';
			for(; i < col; i++){
				scanf("%c", &c);
				m[lin][i] = c - '0';
			}

			scanf("%c", &c);
			scanf("%c", &c);
		}

		lin++;

		cor = 2;
		maior = 0;
		aux = 0;

		for(i = 0; i < lin; i++){
			for(j = 0; j < col; j++){
				if(m[i][j] == 1){
					aux = 0;
					rec(i, j, cor++, &aux);
					maior = aux > maior ? aux : maior;
				}
			}
		}

		printf("%d\n", maior);

		if(t > 0)
			printf("\n");
	}


	return 0;
}