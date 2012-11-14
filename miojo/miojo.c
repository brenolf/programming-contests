#include <stdio.h>

inline int swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	
	int t = 0, A = 0, B = 0, a = 0, b = 0;
	
	scanf("%d %d %d", &t, &a, &b);

	A = a;
	B = b;
	
	while(1){
		if(b > a){
			swap(&a, &b);
			swap(&A, &B);
		}
	
		if(a - b == t)
			break;
		
		b += B;
	}
	
	printf("%d", (a > b) ? a : b);
	
	return 0;
}
