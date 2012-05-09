#include <stdio.h>
#include <stdlib.h>

int main(){
	
	unsigned long int i = 0, a = 0, n = 0, x = 0, r = 0;
	
	scanf("%ld", &a);
	
	scanf("%ld", &n);
	
	for(i=0;i<n;i++){
		scanf("%ld", &x);
		if(x * a >= 40000000)r++;
	}

	printf("%ld", r);

	return 0;
}
