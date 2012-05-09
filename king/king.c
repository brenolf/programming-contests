#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2){
	return *(int*)p1 - *(int*)p2;
}


int main(){
	
	int read[3], a = 0, b = 0, c = 0;
	
	while(1){
		
		scanf("%d %d %d", &read[0], &read[1], &read[2]);
		
		qsort(read, 3, sizeof(int), cmp);
		
		a = read[0];
		b = read[1];
		c = read[2];
		
		if(!a && !b && !c)
			break;
			
		// Set
		
		if(a == b && a == c){
			if(a == 13)
				printf("*");
			else
				printf("%d %d %d", a + 1, a + 1, a + 1);
		}
		
		// Lowest Pair
		
		else if(a == b){
			if(c == 13)
				printf("%d %d %d", 1, a + 1, a + 1);
			else
				printf("%d %d %d", a, a, c + 1);
		}
		
		// Highest Pair

		else if(b == c){
			if(a + 1 == b){
				if(a == 12)
					printf("%d %d %d", 1, 1, 1);
				else
					printf("%d %d %d", b, b, a + 2);
			}else
				printf("%d %d %d", a + 1, b, b);
		}
		
		// Non-Pair
		
		else
			printf("%d %d %d", 1, 1, 2);
			
		printf("\n");
	}

	return 0;
}
