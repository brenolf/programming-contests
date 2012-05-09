#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n = 0, r = 7;
	
	scanf("%d", &n);
	
	if(n > 10){
		if(n < 31)r += (n - 10);
		else r += 20;
	}
	
	if(n > 30){
		if(n < 101)r += (n - 30) * 2;
		else r += 140;
	}
	
	if(n > 100)
		r += (n - 100) * 5;

	printf("%d", r);

	return 0;
}
