#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, p = 2062;
	
	scanf("%d", &i);

	while(p<=i)p+=76;

	printf("%d", p);

	return 0;
}
