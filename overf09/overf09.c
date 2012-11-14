#include <stdio.h>

int main(){
	int n = 0, p = 0, q = 0;
	char c;
	
	scanf("%d", &n);
	scanf("%d %c %d", &p, &c, &q);
	
	if(c == '+')
		p += q;
	else
		p *= q;
		
	printf((p <= n) ? "OK" : "OVERFLOW");

	return 0;
}
