#include <stdio.h>
#define MAX 30001

char people[MAX];
int remaining = 0, n;

inline int next(int i){
	do {
		i = (i + 1) % n;
	} while(!people[i]);

	return i;
}

inline int quit(int i){
	people[i] = 0;
	remaining--;
}

int main(){
	int T, i = 0, k = 1, survivor = 0, rounds;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &n);
		survivor = n;
		rounds = -1;

		do {
			n = survivor;
			rounds++;

			remaining = n;

			for(i = 0; i < n; i++)
				people[i] = 1;

			i = 0;

			while(remaining > 1){
				i = next(i);
				quit(i);
				i = next(i);
			}

			survivor = i + 1;

		} while(survivor != n);

		printf("Case %d: %d %d\n", k++, rounds, survivor);
	}

	return 0;
}