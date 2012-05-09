#include <stdio.h>
#include <stdlib.h>

int V[101];

int main(){
	
	int a = 0, m = 0, i = 0, R = 0, k = 1, n1 = 0, n2 = 0;
	
	while(1){
	
		scanf("%d %d", &a, &m);
		
		if(!a && !m)
			break;
		
		for(i = 1; i <= a; i++)
			V[i] = 0;
		
		R = 0;
		
		for(i = 0; i < m; i++){
			scanf("%d %d", &n1, &n2);
			
			V[n1]++;
			V[n2]++;
			
			if(V[n1] > R)
				R = V[n1];
				
			if(V[n2] > R)
				R = V[n2];
		}
		
		printf("Teste %d\n", k++);
		
		for(i = 1; i <= a; i++)
			if(V[i] == R)
				printf("%d ", i);
		
		printf("\n\n");
	}

	return 0;
}
