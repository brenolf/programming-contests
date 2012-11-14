#include <stdio.h>
#define MAX 10005

inline int between(int a, int ref1, int ref2){
	return ((ref1 > a && ref2 > a) || (ref1 < a && ref2 < a));
}

int main(){
	
	int n = 0, i = 0, read = 0, notas[MAX], ant = 0, prox = 0, loops = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		
		for(i = 0; i < n; i++){
			scanf("%d", &read);
			getchar();
			
			notas[i] = read;
		}
		
		loops = 0;
		
		for(i = 0; i < n; i++){
			ant = (i + n - 1) % n;
			prox = (i + 1) % n;
			
			if(between(notas[i], notas[ant], notas[prox]))
				loops++;
		}
		
		printf("%d\n", loops);
		
	}
	

	return 0;
}
