#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	long long n = 0, k = 0, i = 0;
	
	scanf("%lld", &n);
	
	k = 0;
	
	for(i = 2; i <= sqrt(n) && !k; i++)
		if(n % i == 0)
			k = 1;
			
	printf((k ? "S" : "N"));

	return 0;
}
