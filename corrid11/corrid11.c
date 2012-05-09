#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, j = 0, n = 0, m = 0, read = 0, S = 0, MX = 0, W = 0;
	
	scanf("%d %d", &n, &m);

	for(i = 0; i < n; i++){
		S = 0;
	
		for(j = 0; j < m; j++){
			scanf("%d", &read);
			S += read;
		}
		
		if(!i || S < MX){
			MX = S;
			W = i;
		}
	}
	
	printf("%d", W + 1);

	return 0;
}
