#include <stdio.h>

int main(){
	
	int a, b, c, r;

	while(1){
		scanf("%d %d %d", &a, &b, &c);

		if(!a && !b && !c)
			break;

		a *= a;
		b *= b;
		c *= c;

		r =  (a == b + c);
		r |= (b == a + c);
		r |= (c == a + b);

		printf(r ? "right\n" : "wrong\n");
	}

	return 0;
}
