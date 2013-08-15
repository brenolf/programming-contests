#include <stdio.h>
#define MAX 1000005

int prime[MAX];

inline int reverse(int n){
	int r = 0;

	while(n > 0){
		r *= 10;
		r += (n % 10);
		n /= 10;
	}

	return r;
}

int main(){
	int i = 0, j = 0, u = 0;

	for(i = 0; i < MAX; i++)
		prime[i] = 1;

	for(i = 4; i < MAX; i += 2)
		prime[i] = 0;

	for(i = 3; i <= 1000; i += 2)
		if(prime[i])
			for(j = i * i; j < MAX; j += i)
				prime[j] = 0;


	while(scanf("%d", &i) != EOF){
		if(!prime[i])
			printf("%d is not prime.\n", i);

		else {
			u = reverse(i);

			if(u != i && prime[u])
				printf("%d is emirp.\n", i);

			else
				printf("%d is prime.\n", i);
		}
	}

	return 0;
}