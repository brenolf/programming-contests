#include <stdio.h>
#define MAX 101

inline int min(int a, int b){
	return a < b ? a : b;
}

int main(){

	int n = 0, i = 0, j = 0, k = 0, d = 0, c = 1;
	int f[MAX], ac[MAX][MAX], M[MAX][MAX];

	while(1){

		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		for(i = 0; i < n; i++){
			scanf("%d", &f[i]);
			getchar();
		}

		for(i = 0; i < n; i++)
			ac[i][i] = f[i];

		for(i = 0; i < n; i++){
			for(j = i + 1; j < n; j++)
				ac[i][j] = ac[i][j - 1] + f[j];
		}

		for(i = 0; i < n; i++)
			M[i][i] = 0;

		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - i; j++){
				d = i + j;
				M[i][d] = M[i + 1][d] + ac[i + 1][d];

				for(k = i + 1; k < j; k++)
					M[i][d] = min(M[i][d], M[i][k - 1] + ac[i][k - 1] + M[k + 1][d] + ac[k + 1][d]);

				M[i][d] = min(M[i][d], M[i][d - 1] + ac[i][d - 1]);

			}
		}

		printf("Teste %d\n%d\n\n", c++, M[0][n - 1]);
	}

	return 0;
}