#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int t = 0, n = 0, i = 0, a = 0, s = 0, v = 0;
	char nm[50];
	
	while(1){
		s = 0;
		
		scanf("%d %d", &t, &n);
		
		if(!t && !n)break;
		
		for(i=0;i<t;i++){
			scanf("%s %d", nm, &a);
			s += a;
		}
		
		printf("%d\n", ((3*n)-s));
	}

	return 0;
}
