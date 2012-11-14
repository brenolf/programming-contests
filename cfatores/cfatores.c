#include <stdio.h>
#define MAX 1000001

int primos[MAX];

int main(){
	int i = 0, n = 0, j = 0, c = 0, N = 0, k = 0;
	
	for(i = 0; i < MAX; i++)
		primos[i] = i % 2;

	primos[1] = 0;
	primos[2] = 1;
	
	for(i = 3; i * i < MAX; i++){
		if(primos[i]){		
			for(j = i * i; j < MAX; j += i)
				primos[j] = 0;
		}
	}
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		N = n;
		c = 0;
		k = 1;
		
		for(i = 2; i <= n && i * i <= MAX;){
			if(primos[i] && (n % i == 0)){
				c += k;
				n /= i;
				
				k = 0;
			}else{
				i++;
				k = 1;
			}
		}
		
		if(primos[n])
			c++;
		
		printf("%d : %d\n", N, c);
	}
	
	return 0;
}
