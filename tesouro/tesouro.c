#include <stdio.h>
#define MAX 105
#define CMAX 10055

int M[MAX][CMAX], v[MAX], n = 0, t = 0;

int subsetSum(){
	int i = 0, j = 0;

	for(i = 0; i <= n; i++)
		M[i][0] = 1;

	for(i = 1; i <= t; i++)
		M[0][i] = 0;

	for(i = 1; i <= n; i++){
		for(j = 1; j <= t; j++)
			M[i][j] = M[i - 1][j] || (v[i] <= j && M[i - 1][j - v[i]]);
	}

	return M[n][t];
}

int main(){

	int x = 0, y = 0, k = 1, i = 0, j = 0;

	while(1){
		scanf("%d %d %d", &x, &y, &n);


		if(!x && !y && !n)
			break;

		t = 0;

		for(i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			t += v[i];
		}

		t = (x + y + t);

		if(t % 2 != 0){
			printf("Teste %d\nN\n\n", k++);
			continue;
		}

		t = (t / 2) - x;

		if(subsetSum())
			printf("Teste %d\nS\n\n", k++);
		else
			printf("Teste %d\nN\n\n", k++);
	}

	return 0;
}