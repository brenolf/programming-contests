#include <stdio.h>
#define MAX 210000001

long long int vet[MAX];

int main(){
	int n = 0, i = 0;
	
	vet[0] = 1;
	
	for(i = 1; i < MAX; i++)
		vet[i] = vet[i - 1] + i;
	
	while(1){
		scanf("%d", &n);
		
		if(n < 0)
			break;
		
		printf("%lld\n", vet[n]);
	}

	return 0;
}
