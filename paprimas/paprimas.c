#include <stdio.h>
#define MAX 1040

inline int value(char c){
	if(c >= 'a' && c <= 'z')
		return c - 'a' + 1;
	return c - 'A' + 27;
}

inline int isPrime(int n){
	int i = 0;

	for(i = 2; i < n; i++)
		if(n % i == 0)
			return 0;

	return 1;
}

int main(){
	
	int i = 0, n = 0, primo[MAX + 1];
	char c;

	for(i = 1; i <= MAX; i++)
		primo[i] = isPrime(i);

	while(scanf("%c", &c) != EOF){
		
		if(c == '\n'){

			if(primo[n])
				printf("It is a prime word.\n");
			else
				printf("It is not a prime word.\n");

			n = 0;
			continue;
		}

		n += value(c);
	}

	return 0;
}