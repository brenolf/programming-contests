/**
breno@breno-laptop ~/Documentos/UFSCar/icpc2011/army $ time gcc army.c -o army

	real	0m0.090s
	user	0m0.068s
	sys		0m0.008s
breno@breno-laptop ~/Documentos/UFSCar/icpc2011/army $ time ./army < army.in > army.out

	real	0m0.271s
	user	0m0.220s
	sys		0m0.020s
**/

#include <stdio.h>
#include <stdlib.h>
#define M 100001

typedef struct {
	int l, r;
} buddy;

int main(){
	
	int i = 0, b = 0, s = 0, 
	L = 0, R = 0,
	buddyL = 0, buddyR = 0;

	buddy line[M];
	
	while(1){
		
		scanf("%d %d", &s, &b);
		
		if(!s && !b)
			break;
			
		for(i = 1; i <= s; i++){
			line[i].l = i - 1;
			line[i].r = i + 1;
		}
		
		line[s].r = 0;
		
		for(i = 0; i < b; i++){
			scanf("%d %d", &L, &R);

			buddyL = line[L].l; // Leftmost left friend
			buddyR = line[R].r; // Rightmost right friend
			
			if(buddyL < 1)
				printf("* ");
			else
				printf("%d ", buddyL);
				
				
			if(buddyR < 1)
				printf("*\n");
			else
				printf("%d\n", buddyR);
			
			
			line[buddyR].l = buddyL;
			line[buddyL].r = buddyR;
		}
		printf("-\n");
	}

	return 0;
}
