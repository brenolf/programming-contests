#include <stdio.h>
#include <math.h>

int m[11][11];

int main(){
	
	int n, N, i, j, s, k = 1;

	while(1){
		scanf("%d", &n);

		if(n == 0)
			break;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &m[i][j]);


		N = ceil(((double) n) / 2);

		printf("Case %d:", k++);

		for(i = 0; i < N; i++){
			s = 0;

			for(j = i; j < n - i; j++){
				s += m[i][j];
				s += m[n - i - 1][j];
				s += m[j][i];
				s += m[j][n - i - 1];
			}

			s -= m[i][i] + m[i][n - i - 1] + m[n - i - 1][i] + m[n - i - 1][n - i - 1];

			if(i == n - i - 1)
				s = m[i][i];

			printf(" %d", s);
		}

		printf("\n");
	}


	return 0;
}