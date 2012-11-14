/*
 * Treinamento Maratona 2012 - Problema D - Esteira Maluca
 * Breno Lima de Freitas
 * Mateus Caldas Craveiro
 * Rafael Mariottini Tomazela
 */

#include <stdio.h>
#define MAX 100000001

char stack[MAX];
int top = 0;

int isVowel(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void push(char c){
	stack[top++] = c;
}

void pop(){
	if(!top)
		return;
	
	printf("%c", stack[--top]);
}

int main(){

	char c;

	while(scanf("%c", &c) != EOF){
		if(c == '\n'){
			printf("\n");
			top = 0;
			continue;
		}

		if(isVowel(c))
			push(c);
		else{
			printf("%c", c);
			pop();
		}
	}

	return 0;
}
