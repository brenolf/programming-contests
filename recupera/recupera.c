#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, s = 0, ax = 0, i = 0, r = 0, k = 0;
	
	while(scanf("%d", &n)!=EOF){	
		s = 0;
		r = 0;
		
		for(i=0;i<n;i++){
			scanf("%d", &ax);
			
			if(ax==s)r = 1;
			
			if(!r)s += ax;
		}
		
		printf("Instancia %d\n", ++k);
		if(r)printf("%d\n\n", s);
		else printf("nao achei\n\n");
		
	}

	return 0;
}
