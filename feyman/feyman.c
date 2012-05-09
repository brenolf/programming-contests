#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0;
	
	while(1){
		scanf("%d", &i);
		
		if(!i)break;
		
		printf("%d\n", ((i*(i+1)*(2*i+1))/6));
	}

	return 0;
}
