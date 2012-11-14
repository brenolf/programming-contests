#include <stdio.h>

int main(){
	
	int n = 0, t = 0, v = 0, k = 0;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &t, &v);
		k += t * v;
	}
	
	printf("%d", k);

	return 0;
}
