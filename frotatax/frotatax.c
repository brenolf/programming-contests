#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float a = 0, g = 0, ra = 0, rg = 0;
	
	scanf("%f %f %f %f", &a, &g, &ra, &rg);
	
	if((a/ra) < (g/rg))printf("A");
	else printf("G");

	return 0;
}
