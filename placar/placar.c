#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char an[21], n[21];
	int t = 0, i = 0, am = 0, m = 0, k = 0;
	
	while(scanf("%d", &t)!=EOF){
		
		scanf("%s %d", n, &m);
		
		for(i=1;i<t;i++){
			scanf("%s %d", an, &am);
			
			if(am<m || (am==m && strcmp(n, an)<0)){
				strcpy(n, an);
				m = am;	
			}
		}
		
		printf("Instancia %d\n", ++k);
		printf("%s\n\n", n);
	}

	return 0;
}
