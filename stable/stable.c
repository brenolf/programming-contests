// UVA - Stable grid
#include <stdio.h>
#define MAX 101

int main(){
	int T, n, i, k = 1, x, R, m[MAX];

	scanf("%d", &T);

	while(T--){
		scanf("%d", &n);

		for(i = 0; i < MAX; i++)
			m[i] = 0;

		R = 1;

		for(i = 0; i < n * n; i++){
			scanf("%d", &x);
			R &= (++m[x] <= n);
		}

		printf("Case %d: %s\n", k++, (R ? "yes" : "no"));
	}
	
	return 0;
}