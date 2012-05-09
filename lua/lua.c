#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int i = 0, n = 0, m = 0, add = 0, b = 0, k = 0, t[10001], ma = 0, mx = 0, mi = 0;
	
	while(1){
		scanf("%d %d", &n, &m);
		
		if(!n && !m)break;
		
		b = m;
		
		mi = 0;
		mx = 0;
		ma = 0;
		add = 0;
		
		for(i=0;i<n;i++){
			scanf("%d", &t[i]);
			if(m>0){
				m--;
				ma += t[i];
				if(!m){
					mx = ma;
					mi = ma;
				}
			}else{
				ma = ma - t[add++] + t[i];
			
				if(ma > mx)mx = ma;
				if(ma < mi)mi = ma;
			}
		}
		
		printf("Teste %d\n", ++k);
		printf("%d %d\n\n", mi/b, mx/b);
	}

	return 0;
}
