#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int i = 0, n = 0, k = 1, four[16], Q = 0;
	
	four[0] = 1;
	
	for(i = 1; i < 16; i++)
		four[i] = four[i - 1] * 4;
	
	while(1){
		scanf("%d", &i);
		
		if(i < 0)break;
		
		Q = four[i];
		
		printf("Teste %d\n%d\n\n", k++, (int) (pow(2, i + 1) + Q) + 1);
	}

	return 0;
}
