#include <stdio.h>

int main(){
	
	int d = 0, n = 0, k = 0, i = 0, j = 0, cols = 0, lines = 0;
	int m[99][13];
	
	scanf("%d", &d);
	
	while(d--){
		scanf("%d %d", &n, &k);
		
		for(i = 0; i <= k; i++)
			m[i][0] = 0;
			
		for(i = 0; i <= n; i++)
			m[0][i] = 1;
			
		for(i = 1; i <= k; i++){
			for(j = 1; j <= n; j++){
				m[i][j] = 0;

				lines = i;
				cols = 0;
				
				while(lines >= 0 && cols < j){
					m[i][j] += m[lines][j - 1];
					lines--;
					cols++;
				}
			}
		}
		
		printf("%d\n", m[k][n]);
	}

	return 0;
}

/*int permut(int n, int k){
	if(!n)
		return 0;
	
	if(!k)
		return 1;
	
	int i = 0, R = 0;
	
	for(i = k; i > k - n && i >= 0; i--)
		R += permut(n - 1, i);
	
	return R;
}

int main(){
	
	int d = 0, n = 0, k = 0;
	
	scanf("%d", &d);
	
	while(d--){
		scanf("%d %d", &n, &k);
		printf("%d\n", permut(n, k));
	}

	return 0;
}*/
