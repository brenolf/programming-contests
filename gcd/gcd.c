#include <stdio.h>

int gcd(int a, int b){
	if(!b)
		return a;
	return gcd(b, a % b);
}

inline int solve(int N){
	int G=0,i,j;
	for(i=1;i<N;i++)
	for(j=i+1;j<=N;j++)
	{
	    G+=gcd(i,j);
	}
	return G;
}

int main(){

	int n = 0;

	while(1){
		scanf("%d", &n);

		if(!n)
			break;

		printf("%d\n", solve(n));
	}
	
	return 0;
}