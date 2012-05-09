#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n = 0, k = 0, i = 0;
	
	scanf("%d", &n);
	
	if(n < 0)
		n *= -1;
	
	if(n == 0 || n == 1)
		k = 1;
	
	for(i = 2; i <= sqrt(n) && !k; i++)
		if(n % i == 0)
			k = 1;

	if(k)
		printf("nao");
	else
		printf("sim");

	return 0;
}
