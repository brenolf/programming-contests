#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char n[101], r[101];
	int d = 0, i = 0, c = 0, l = 0, zero = 0, t = 0;
	
	while(1){
		c = 0;
		t = 0;
		zero = 0;
		
		scanf("%d %s", &d, n);
		
		if(!d&&!strcmp(n, "0"))break;
		
		d+=48;
		l = strlen(n);
		
		for(i=0;i<l;i++){
			if((zero&&n[i]==48))continue;
			
			zero = 0;
			if(n[i]!=d){
				r[c++] = n[i];
				t++;
			}
			
			if(i+1<l&&n[i]!=48)zero = 1;
		}
		
		if(!t)r[c++] = '0';
		r[c] = '\0';
		
		printf("%s\n", r);
	}
	
	return 0;
}
