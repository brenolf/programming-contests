#include <stdio.h>
#include <stdlib.h>

int main(){
	char s[201];
	int i = 0, r = 0;
	float c = 0;
	
	while(1){
		scanf("%s", s);
		
		if(s[0] == '*')break;
		
		c = 0;
		r = 0;
		i = -1;
		
		while(s[i++] != '\0'){
			if(s[i] == '/'){
				if(c == 1)r++;
				c = 0;
				continue;
			}
			
			switch(s[i]){
				case 'W': c += 1; 		break;
				case 'H': c += 0.5; 	break;
				case 'Q': c += 0.25; 	break;
				case 'E': c += 0.125; 	break;
				case 'S': c += 0.0625; 	break;
				case 'T': c += 0.03125; break;
				case 'X': c += 0.015625;
			}
		}
		
		printf("%d\n", r);
	}
	
	return 0;
}