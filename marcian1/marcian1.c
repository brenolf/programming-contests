#include <stdio.h>
#include <math.h>

int main(){

	int l = 0, a = 0, p = 0, r = 0;

	scanf("%d %d %d %d", &l, &a, &p, &r);
	
	l = l * l + a * a + p * p;

	printf((2 * r >= sqrt(l)) ? "S" : "N");

	return 0;
}