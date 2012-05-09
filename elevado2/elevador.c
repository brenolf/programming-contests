#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, c = 0, s = 0, e = 0, r = 0, a = 0;
	
	scanf("%d %d", &n, &c);

	for(i=0;i<n;i++){
		scanf("%d %d", &s, &e);
		
		if(!r){
			a += e - s;
			if(a>c)r = 1;
		}
	}
	
	printf("%c", r?'S':'N');

	return 0;
}
