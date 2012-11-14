#include <stdio.h>

int main(){
	int i = 0, n = 0, d = 0;
	int a = 0, p = 0, R = 1;
	
	scanf("%d %d", &n, &d);
	
	scanf("%d", &a);
	
	for(i = 1; i < n; i++){
		scanf("%d", &p);

		if(p - a > d)
			R = 0;

		a = p;
	}

	if(42195 - a > d)
		R = 0;
	
	printf(R ? "S" : "N");

	return 0;
}
