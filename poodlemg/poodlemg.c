#include <stdio.h>

int main(){

	int n = 0, p = 0, i = 0;

	while(1){

		scanf("%d %d", &n, &p);

		if(!n && !p)
			break;

		if(n % p)
			n += p;

		n /= p;
		n -= 6;

		printf("Poo");
		for(i = 0; i < n && i < 14; i++)
			printf("o");
		printf("dle\n");
	}

	return 0;
}