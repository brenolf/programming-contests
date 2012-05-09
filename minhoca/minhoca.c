#include <stdio.h>
#include <stdlib.h>

inline int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	
	int M[100], L = 0, r = 0, n = 0, m = 0, i = 0, j = 0;
	int maxCol = 0, maxLine = 0;
	
	scanf("%d %d", &n, &m);
	
	for(i = 0; i < m; i++)
		M[i] = 0;
	
	for(i = 0; i < n; i++){
		L = 0;
	
		for(j = 0; j < m; j++){
			scanf("%d", &r);
			L += r;
			M[j] += r;
		}
		
		maxLine = max(L, maxLine);
	}
	
	for(i = 0; i < m; i++)
		maxCol = max(M[i], maxCol);	
	
	printf("%d", max(maxCol, maxLine));
	
	return 0;
}