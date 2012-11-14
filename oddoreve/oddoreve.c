#include <stdio.h>
#define M 101

inline int abs(int a){
	return a < 0 ? -1 * a : a;
}

int main(){
	
	int n = 0, i = 0, rx, ry, ix = 0, px = 0, iy = 0, py = 0;
	
	
	while(1){
		scanf("%d", &n);
		
		if(!n)
			break;
			
		ix = px = 0;
		iy = py = 0;	
		
		
		for(i = 0; i < n; i++){
			scanf("%d", &rx);
			getchar();
			
			if(rx % 2 == 0)
				px++;
			else
				ix++;
		}
		
		for(i = 0; i < n; i++){
			scanf("%d", &ry);
			getchar();
			
			if(ry % 2 == 0)
				py++;
			else
				iy++;
		}
		
		px -= iy;
		
		if(px < 0)
			px = 0;
			
		ix -= py;
		
		if(ix < 0)
			ix = 0;
		
		printf("%d\n", px + ix);
	}

	return 0;
}
