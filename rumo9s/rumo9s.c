#include <stdio.h>
#include <string.h>
#define MAX 1001


int main(){
	
	char c, str[MAX];
	int I = 0, sum = 0, aux = 0, n = 0, i = 0, dig = 0;
	
	while(1){
		sum = 0;
		I = 0;
		
		while(1){
			scanf("%c", &c);
			
			if(c == '\n')
				break;
			
			sum += c - '0';
			str[I++] = c;
		}
		
		if(sum == 0)
			break;
		
		for(i = I; i < MAX; i++)
			str[i] = '\0';

		n = 0;
		dig = 10;
		
		while(sum % 9 == 0 && dig > 1){
			aux = sum;
			sum = 0;
			dig = 0;
		
			while(aux > 0){
				sum += aux % 10;
				aux /= 10;
				dig++;
			}
			
			n++;
		}
		
		if(sum % 9 != 0)
			n = -1;
		
		if(n < 0)
			printf("%s is not a multiple of 9.\n", str);
		else
			printf("%s is a multiple of 9 and has 9-degree %d.\n", str, n);
	}
	
	return 0;
}
