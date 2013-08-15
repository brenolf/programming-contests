#include <stdio.h>

int trees[20] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};

/*int catalanN[30];

int catalan(int n){
	if(n == 0)
		return 1;

	int i = 0, r = 0, a, b;
	n--;

	for(i = 0; i <= n; i++){
		a = catalanN[i];
		b = catalanN[n - i];

		if(a == -1)
			a = catalanN[i] = catalan(i);

		if(b == -1)
			b = catalanN[n - i] = catalan(n - i);

		r += a * b;
	}

	return r;
}*/

inline int lookFor(int n){
	int i = 0;

	for(i = 0; i < 30; i++)
		if(trees[i] == n)
			return i;

	return -1;
}

int main(){
	
	int n = 0, i = 0;

	/*for(i = 0; i < 30; i++)
		catalanN[i] = -1;

	catalanN[0] = 1;

	for(i = 0; i < 30; i++){
		trees[i] = catalan(i);
		printf("%d\n", trees[i]);
	}

	trees[0] = 0;*/

	while(scanf("%d", &n) != EOF)
		printf("%d\n", lookFor(n));

	return 0;
}