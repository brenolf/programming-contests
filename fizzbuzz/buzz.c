#include <stdio.h>
#include <stdlib.h>

int tem(int n, int find){
	if(n <= 0)
		return 0;
	if(n % 10 == find)
		return 1;
	
	return tem(n/10, find);
}

int main(){
	int i = 0, m = 10000000, k = 0;
	
	for(i = 1; i < m; i++, k = 0){
	
		if(i % 3 == 0 || tem(i, 3)){
			printf("Fizz");
			k++;
		}
		
		if(i % 5 == 0 || tem(i, 5)){
			printf("Buzz");
			k++;
		}
		
		if(!k)
			printf("%d", i);
		
		printf("\n");
	}

	return 0;
}
