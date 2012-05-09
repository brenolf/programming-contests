#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int A = 0, B = 0, C = 0, a = 0, b = 0, c = 0;
	
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &A, &B, &C);

	printf("%d", (A/a) * (B/b) * (C/c));

	return 0;
}
