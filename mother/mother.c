#include <stdio.h>
#include <string.h>
#define MAX 501

char str[MAX], cpy[MAX];

inline int isLetter(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline char lower(char c){
	if(c >= 'A' && c <= 'Z')
		return c - ('A' - 'a');
	return c;
}

int main(){

	int len, i, j;
	char c;

	while(1){
		
		i = 0;
		while(1){
			scanf("%c", &c);

			if(c == '\n')
				break;

			if(isLetter(c))
				str[i++] = lower(c);
		}

		len = i;
		str[len] = '\0';

		if(!strcmp(str, "done"))
			break;

		j = 0;
		for(i = len - 1; i >= 0; i--)
			cpy[j++] = str[i];

		cpy[j] = '\0';

		if(!strcmp(cpy, str))
			printf("You won't be eaten!\n");
		else
			printf("Uh oh..\n");
	}

	return 0;
}