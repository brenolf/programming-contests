#include <stdio.h>
// ( a ^ p ) % m
int bigmod ( long long a, int p, int m )
{
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p & 1 ) // If power is odd, a ^ 7 = a * a ^ 6
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m; // Multipication    may exceed int range
    }
    else
    {
        long long c = bigmod ( a, p / 2, m ); // Multipication may exceed int range
        return ( c * c ) % m;
    }
}


int main(){
	
	long long int b, p, m;
	
	while(1){
		if(scanf("%lld", &b) == EOF)
			break;
		
		getchar();
		scanf("%lld", &p);
		getchar();
		scanf("%lld", &m);
		getchar();
		getchar();
		
		printf("%d\n", bigmod(b, p, m));
	}
		
	return 0;
}
