#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	
	char n[61];
	
	int i = 0, k = 0, p = 0;
	
	unsigned long long int r = 0;
	
	while(scanf("%s", n)!=EOF){
		r = 0;
		p = strlen(n)-1;
		
		for(i=0;i<strlen(n);i++){
			if(n[i]=='a')continue;
			
			r += (unsigned long long int) pow(2, p-i);
		}
		
		printf("Palavra %d\n%llu\n\n", ++k, r);
	}

	return 0;
}
