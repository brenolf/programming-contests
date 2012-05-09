#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, i = 0, ax = 0, ac = 0, r = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		ac = 0;
		r = 0;
		
		for(i=0;i<n;i++){
			scanf("%d", &ax);
			
			ac+=ax;
			
			if(ac>r)r = ac;
			if(ac<0)ac = 0;
		}
		
		if(r>0)printf("The maximum winning streak is %d.\n", r);
		else printf("Losing streak.\n");
	}

	return 0;
}
