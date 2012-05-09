#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, i = 0, t = 0, v = 0, R = 0;
	
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
		
		R = 0;
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &t, &v);
			R += v/2;
		}
		
		R /= 2;
		
		printf("%d\n", R);
		
	}
	
	return 0;
}