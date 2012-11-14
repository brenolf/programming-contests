#include <stdio.h>

int a = 0, b = 0, c = 0;

inline int abs(int a){
	return a < 0 ? -a : a;
}

inline int valid(){
	if((abs(b - c) < a && a < b + c) && (abs(a - c) < b && b < a + c) && (abs(b - a) < c && c < b + a))
		return 1;
	return 0;
}

int main(){
	
	scanf("%d %d %d", &a, &b, &c);
	
	int A = a * a, B = b * b, C = c * c;
	
	if(!valid())
		printf("n");
	else if(A == B + C ^ B == A + C ^ C == A + B)
		printf("r");
	else if(A > B + C ^ B > A + C ^ C > B + A)
		printf("o");
	else if(A < B + C ^ B < A + C ^ C < B + A)
		printf("a");

	return 0;
}
