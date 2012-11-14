/*
 * Treinamento Maratona 2012 - Problema E - O Empreiteiro Encrencado
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */

#include <stdio.h>

int euclides(int a, int b){
	if(!b)
		return a;
	return euclides(b, a % b);
}

int main(){
	int a = 0, b = 0;

	while(1){
		scanf("%d %d", &a, &b);

		if(!a && !b)
			break;

		printf("%d\n", euclides(a, b));
	}


	return 0;
}
