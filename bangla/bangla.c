#include <stdio.h>

void read(long int n){
	long int x;

	x = n / 10000000;
	if(x != 0){
		// kuti
		read(x);
		printf(" kuti");
		read(n - x * 10000000);
		return;
	}

	x = n / 100000;
	if(x != 0){
		// lakh
		read(x);
		printf(" lakh");
		read(n - x * 100000);
		return;
	}

	x = n / 1000;
	if(x != 0){
		// hajar
		read(x);
		printf(" hajar");
		read(n - x * 1000);
		return;
	}

	x = n / 100;
	if(x != 0){
		// shata
		read(x);
		printf(" shata");
		read(n - x * 100);
		return;
	}

	if(n != 0)
		printf(" %ld", n);
}

int main(){

	int k = 1;
	long int n;

	while(scanf("%ld", &n) != EOF){
		printf("%4d.", k++);

		if(n != 0)
			read(n);
		else
			printf(" 0");

		printf("\n");
	}


	return 0;
}