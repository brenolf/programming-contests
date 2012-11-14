#include <stdio.h>
#include <stdlib.h>
#define M 100005

int main(){
	
	int i = 0, n = 0, k = 0, a = 0, b = 0, pai[M];
	char r;

	scanf("%d%d", &n, &k);
	
	for(i = 0; i < n; i++)
		pai[i] = i;
	
	for(i = 0; i < k; i++){
		scanf(" %c %d %d", &r, &a, &b);
		
		a--;
		b--;

		while(a != pai[a])a = pai[a];
		while(b != pai[b])b = pai[b];
		
		if(r == 'C')
			printf((a == b ? "S\n" : "N\n"));
		else
			pai[a] = b;
	}

	return 0;
}
