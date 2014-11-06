#include <stdio.h>
#include <stdlib.h>



int main(int argc, char*argv[]){
	
	int i = 0, n = 0, r = 0, resp = 1;
	char op;
	long double rr = 1;

	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d %c", &r, &op);
		//getPrimo(r, op);
		if (op == '*')
			rr *= r;
		else
			rr /= r;
	}

	//for(i = 0; i < 4; i++)
	//	resp *= power(pr[i], bucket[i]);

	printf("%d\n", (int) rr);

	return 0;
}
