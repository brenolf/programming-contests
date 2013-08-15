#include <stdio.h>
#define MAX 4000

int seq[MAX];

inline int abs(int n){
	return n < 0 ? -n : n;
}

int main(){

	int n, i, a, b;

	while(scanf("%d", &n) != EOF){
		for(i = 1; i < n; i++)
			seq[i] = 0;

		scanf("%d", &a);

		for(i = 1; i < n; i++){
			scanf("%d", &b);
			seq[abs(a - b)]++;
			a = b;
		}

		a = 0;

		for(i = 1; i < n; i++){
			if(seq[i] != 1){
				a = 1;
				break;
			}
		}

		printf(a ? "Not jolly\n" : "Jolly\n");
	}

	return 0;
}