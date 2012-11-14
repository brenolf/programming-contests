#include <stdio.h>
#define MAX 1005

int main(){
	int com[MAX], icom = 0, n = 0, read = 0, i = 0, j = 0, R = 0, c = 0;
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
		
		icom = 0;
		R = 0;

		for(i = 0; i < n; i++){
			scanf("%d", &read);
			getchar();
			
			com[icom++] = read;
		}

		for(i = 0; i < icom; i++){
			
			c = i;
			
			for(j = i - 1; j >= 0; j--){
				if(com[j] == com[i]){
					c = i - j - com[i];
					break;
				}
			}
			
			R += com[i] + c;
		}
		
		printf("%d\n", R);
		
	}

	return 0;
}
