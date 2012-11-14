#include <stdio.h>
#define MAX 100002

#define H 0
#define E 1
#define R 2

int vet[3][MAX], player[MAX], N = 0;

int query(int type, int a, int b){
	if(!a){
		int sum = 0;

		for(; b >= 0; b = (b & (b + 1)) - 1)
			sum += vet[type][b];

		return sum;
	}

	return query(type, 0, b) - query(type, 0, a - 1);
}

void add(int type, int i, int plus){
	for(; i < N; i |= i + 1)
		vet[type][i] += plus;
}

int main(){
	
	int m = 0, a = 0, b = 0, i = 0;
	char c;

	while(scanf("%d %d", &N, &m) != EOF){
		getchar();

		for(i = 0; i <= N; i++){
			vet[H][i] = 0;
			vet[E][i] = 0;
			vet[R][i] = 0;
			player[i] = H;
		}

		for(i = 1; i <= N; i++)
			add(H, i, 1);

		while(m--){
			scanf("%c %d %d", &c, &a, &b);
			getchar();

			if(c == 'M'){
				for(i = a; i <= b; i++){
					add(player[i], i, -1);

					player[i] = (player[i] + 1) % 3;

					add(player[i], i, 1);
				}
			}else
				printf("%d %d %d\n", query(H, a, b) % 3, query(E, a, b) % 3, query(R, a, b) % 3);
		}

		printf("\n");
	}


	return 0;
}
