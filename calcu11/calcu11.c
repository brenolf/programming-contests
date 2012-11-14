#include <stdio.h>
#include <stdlib.h>

int pr[] = {2, 3, 5, 7}, bucket[] = {0, 0, 0, 0};

inline void getPrimo(int n, char s){
	int i = 0;
	
	for(i = 0; i < 4; i++){
		while(n % pr[i] == 0){
			n /= pr[i];
		
			if(s == '*')
				bucket[i]++;
			else
				bucket[i]--;
		}
	}
}

inline int power(int n, int p){
	int i = 0;
	long r = 1;
	
	for(i = 0; i < p; i++)
		r *= n;
	
	return r;
}

int main(){
	
	int i = 0, n = 0, r = 0, resp = 1;
	char op;

	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%d %c", &r, &op);
		getPrimo(r, op);
	}

	for(i = 0; i < 4; i++)
		resp *= power(pr[i], bucket[i]);
	
	printf("%d\n", resp);

	return 0;
}
