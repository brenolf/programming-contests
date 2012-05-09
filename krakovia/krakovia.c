#include <stdio.h>
#include <stdlib.h>

char r[21], s[26], d[26];
int LEN = 0, k = 0;

inline void print(){
	int i = LEN;

	printf("Bill #%d costs ", ++k);
	
	for(; i >= 0; i--)
		printf("%c", s[i]);
	
	printf(": each friend should pay ");
	
	
	printf("\n\n");
}

inline int len(){
	int i = 0;
	
	while(r[i])
		i++;
	
	return i;
}

inline void cpy(){
	int i = len() - 1, c = 0;

	LEN = i;
	
	for(; i >= 0; i--)
		s[c++] = r[i];
}

inline void adder(int pos, int num){
	int i = pos, carry = 1, r = 0;

	for(; carry; i++){
		if(!s[i])
			LEN++;
	
		carry = s[i] - 48 + num;
		
		r = carry % 10;
		carry /= 10;
		
		s[i] = r + 48;
		
		num = carry;
	}
}

inline void sum(){
	int i = len() - 1, c = 0;

	for(; i >= 0; i--)
		adder(c++, r[i] - 48);
}

inline void divd(){
	int i = LEN, j = 0, n = 0, b = 1;
	
	for(; i > 0; i-=5){
		
		b = 1;
		
		for(j = i; j >= i - 5; j--){
			n += b * (s[i] - 48);
			b *= 10;
		}
		
		n /= 2;
		
		while(n % 10){
			
		}
		
	}
}

int main(){
	
	int n = 0, m = 0, i = 0;
	
	while(1){
		scanf("%d %d", &n, &m);
		
		if(!n && !m)
			break;
		
		for(i = 0; i < 26; i++){
			s[i] = '\0';
			d[i] = '\0';
		}
		
		scanf("%s", r);
		
		cpy();
		
		for(i = 1; i < n; i++){
			scanf("%s", r);
			sum();
		}
		
		print();
	}
	
	return 0;
}