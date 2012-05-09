#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = 0, i = 0, l = 0, c = 0, e = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		while(n--){
			e = 0;
			c = 0;
		
			for(i=0;i<5;i++){
				scanf("%d", &l);
				
				if(l<=127){
					c++;
					e = i;
				}
			}
			
			if(c==1)printf("%c\n", e+65);
			else printf("*\n");
		}
	}

	return 0;
}
