#include <stdio.h>

int main(){
	int l = 0, d = 0, k = 0, p = 0, T = 0, i = 0;
	
	scanf("%d %d", &l, &d);
	scanf("%d %d", &k, &p);

	printf("%d", ((l / d) * p) + (k * l));

	return 0;
}
