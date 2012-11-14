#include <stdio.h>
#define MAX 10001

int main(){

	int n = 0, j = 0, deck[MAX], montes[MAX], faces[MAX], top = 0, i = 0, atual = 0, key = 0, maior = 0;

	while(1){
		scanf("%d %d", &n, &j);

		if(!n && !j)
			break;

		for(i = 0; i < n; i++){
			scanf("%d", &deck[i]);
			getchar();
		}

		for(i = 0; i < j; i++){
			montes[i] = 0;
			faces[i] = 0;
		}

		atual = 0;
		maior = -1;
		top = -1;

		while(++top < n){
			key = 0;

			for(i = 0; i < top; i++){
				if(deck[i] == deck[top]){
					key = 1;
					deck[i] = 0; // tira carta do descarte
					break;
				}
			}
			
			//6 3
//1 2 1 2 1 2

			if(key){ // area de descarte
				montes[atual] += 2;
				faces[atual] = deck[top];
				deck[top] = 0;
			}else{
				key = 1;

				if(deck[top] == faces[atual]){ // igual ao topo do atual
					deck[top] = 0;
					montes[atual]++;
				}else{
					key = 0;

					for(i = 0; i < j; i++){
						if(faces[i] == deck[top] && i != atual){ // Igual ao topo de um outro jogador
							montes[atual] += montes[i] + 1;
							montes[i] = 0;
							faces[i] = 0;
							faces[atual] = deck[top];
							key = 1;
							deck[top] = 0;
							break;
						}
					}
				}

			}

			if(montes[atual] > maior)
				maior = montes[atual];
				
			if(!key) // Nao aconteceu nada, proxima rodada
				atual = (atual + 1) % j;
		}

		printf("%d ", maior);

		for(i = 0; i < j; i++)
			if(montes[i] == maior)
				printf("%d ", i + 1);

		printf("\n");

	}

	return 0;
}
