#include <stdio.h>

int getMax(int n, int k){
	if(!n)
		return 0;

	if(n <= k)
		return 1;

	int p1 = n / 2, p2 = n - p1;

	if(p1 == p2)
		return 2 * getMax(p2, k);

	return getMax(p1, k) + getMax(p2, k);
}

int main(){
	int n = 0, k = 0;

	while(1){
		scanf("%d %d", &n, &k);

		if(!n && !k)
			break;

		printf("%d\n", getMax(n, k));
	}

	return 0;
}