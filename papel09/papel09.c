#include <stdio.h>

int main(){
	int c = 0, p = 0, f = 0;
	
	scanf("%d %d %d", &c, &p, &f);
	
	if(c * f <= p)
		printf("S");
	else
		printf("N");

	return 0;
}
