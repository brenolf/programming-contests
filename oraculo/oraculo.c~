#include <stdio.h>
#include <stdlib.h>

int main(){
	int i = 0, T = 0, n = 0, k = 0, mul = 0, s = 0;
	char e;
	unsigned long long int r = 0;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++){
		scanf("%d", &n);
		
		k = 0;
		
		do{
			scanf("%c", &e);
			k++;
		}while(e == '!');
		
		r = n;
		mul = 1;
		k--;
		
		while(1){
			s = n - mul * k;
		
			if(s < 1)
				break;
		
			r *= s;
			mul++;
		}
		
		printf("%llu\n", r);
	}
	
	return 0;	
}
