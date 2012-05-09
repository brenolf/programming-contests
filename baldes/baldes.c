#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, x[100001], i = 0, j = 0, r = 0;
	
	while(1){
	
		scanf("%d", &n);
		
		if(!n)break;
		
		for(i=0;i<n;i++)scanf("%d", &x[i]);
		
		r = 0;
		
		//1 5 3 4 2
		
		for(i=n-1;i>0;i--){
			for(j=0;j<i;j++){
				if(x[j]>x[j+1]){
					r++;
					x[j] = x[j+1]^x[j];
					x[j+1] = x[j]^x[j+1];
					x[j] = x[j+1]^x[j];
				}
			}
		}
		
		if(r%2==0)printf("Carlos\n");
		else printf("Marcelo\n");
	}

	return 0;
}
