#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 0, d = 0, i = 0, ax = 0, at = 0, d1 = 0, d2 = 0;
	
	while(1){
		scanf("%d %d", &a, &d);
		
		if(!a && !d)break;
		
		for(i=0;i<a;i++){
			scanf("%d", &ax);
			
			if(!i)at = ax;
			else if(ax<at)at = ax;
		}
		
		for(i=0;i<d;i++){
			scanf("%d", &ax);
			
			if(!i)d1 = ax;
			else if(i==1){
				d2 = ax;
				if(d2<d1){
					d1 = d1^d2;
					d2 = d2^d1;
					d1 = d2^d1;
				}
			}else{
				if(ax<d1){
					d1 = d1^ax;
					ax = ax^d1;
					d1 = ax^d1;
					d2 = ax;
				}else if(ax<d2)d2 = ax;
			}
		}
		
		if(d==1)d2 = d1;
		
		if(at<d2)printf("Y\n");
		else printf("N\n");
	}

	return 0;
}
