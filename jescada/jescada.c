#include <stdio.h>

int main(){

	int n = 0, t = 0, i = 0, u = 0, a = 0;

	scanf("%d", &n);

	t = 10 * n;

	for(i = 0; i < n; i++){
		u = 10 + a;
		scanf("%d", &a);

		if(i && a < u)
			t -= (u - a);
	}

	printf("%d", t);

	return 0;
}