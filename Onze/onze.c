#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char n[1001];
	int sp = 0, si = 0, i = 0;
	
	while(1){
		scanf("%s", n);
		
		sp = 0;
		si = 0;
		
		if(!strcmp(n, "0"))break;
		
		for(i=0;i<strlen(n);i++){
			if(i%2==0)sp += (n[i]-48);
			else si += (n[i]-48);
		}
		
		if((si%11) == (sp%11))printf("%s is a multiple of 11.\n", n);
		else printf("%s is not a multiple of 11.\n", n);
	}
	

	return 0;
}
