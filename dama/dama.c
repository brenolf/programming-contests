/*
 * Treinamento Maratona 2012 - Problema F - Dama
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */

#include <stdio.h>

int main(){
	
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	
	while(1){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if(!x1 && !y1 && !x2 && !y2)
			break;

		if(x1 == x2 && y1 == y2)
			printf("0");
		else if(x1 == x2 || y1 == y2 || (y2 - y1 == x2 - x1) || (y2 - y1 == x1 - x2))
			printf("1");
		else
			printf("2");

		printf("\n");
	}

	return 0;
}
