#include <stdio.h>
#define MAX 1005

int main(){
	
	int p = 0, n = 0, c = 0, m[MAX][MAX], um = 0, tot = 0, i = 0, j = 0;
	
	while(1){
		scanf("%d %d %d", &p, &n, &c);
		
		if(!p && !n && !c)
			break;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < p; j++){
				scanf("%d", &m[i][j]);
				getchar();
			}
		
		tot = 0;
		
		for(i = 0; i < p; i++){
			for(j = 0; j < n; j++){			
				if(m[j][i])
					um++;
				else{
					if(um >= c)
						tot++;
					um = 0;
				}
				
				if(j + 1 == n){
					if(um >= c)
						tot++;
					um = 0;					
				}
			}
		}
		
		printf("%d\n", tot);
		
	}

	return 0;
}
