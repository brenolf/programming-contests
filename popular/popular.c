#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, j = 0, n = 0, el[101], a = 0, m = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)break;
		
		for(i=0;i<n;i++)el[i] = 0;
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d", &a);
				if(a)el[j]++;
			}
		}
		
		m = el[0];
		
		for(i=1;i<n;i++){
			if(el[i]>m)m = el[i];
		}
		
		printf("%d\n", m);
	}

	return 0;
}
