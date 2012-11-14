#include <stdio.h>

int main(){
	int n = 0, t = 0, zeros = 0, i = 0;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d", &t);
		
		zeros = 0;
		
		for(i = 5; i <= t; i *= 5)
			zeros += (t / i);
		
		printf("%d\n", zeros);
	}
	
	return 0;
}
