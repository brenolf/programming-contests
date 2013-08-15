#include <stdio.h>
#define max(a, b) a > b ? a : b

int main(){
	
	int t = 0, n, i, r, a, k = 1;

	scanf("%d", &t);

	while(t--){

		scanf("%d", &n);

		scanf("%d", &r);

		for(i = 1; i < n; i++){
			scanf("%d", &a);
			r = max(r, a);
		}

		printf("Case %d: %d\n", k++, r);
	}

	return 0;
}