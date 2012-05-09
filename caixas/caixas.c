#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, p = 0, q = 0, a = 0, c = 0, rg = 0, r = 0;
	
	while(1){
		
		scanf("%d %d", &n, &p);
		
		if(!n && !p)break;
		
		c = 0;
		r = 0;
		
		while(p--){
			scanf("%d", &q);
		
			rg = 0;
			
			if(!r){
				for(i=0;i<q;i++){
					scanf("%d", &a);
					if(a==1){
						r = 1;
						rg = 0;
					}else rg++;	
				}
			
				c += rg;
			}else{
				for(i=0;i<q;i++)scanf("%d", &a);
			}
		}
		
		printf("%d\n", c);
	}

	return 0;
}
