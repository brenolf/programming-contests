#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, n = 0, x = 0, y = 0, k = 1, R = 0;
	
	while(1){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if(!x1 && !y1 && !x2 && !y2)
			break;
		
		scanf("%d", &n);
		
		R = 0;
		
		for(i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			
			if(x >= x1 && x <= x2 && y <= y1 && y >= y2)
				R++;
		}
		
		printf("Teste %d\n%d\n\n", k++, R);
		
	}

	return 0;
}
