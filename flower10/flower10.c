#include <stdio.h>
#include <string.h>

int main(){
	
	char c, L, l;
	int sp = 0, i = 0, k = 1;
	
	while(1){	
		c = getchar();
		
		if(c == '*'){
			getchar();
			break;
		}
		
		if(c == '\n'){
			printf(k ? "Y\n" : "N\n");
			sp = 0;
			k = 1;
			continue;
		}
		
		if(!k)
			continue;
		
		if(!sp){
			if(c >= 'A' && c <= 'Z'){
				l = c + 32;
				L = c;
			}else{
				l = c;
				L = c - 32;
			}
			
			sp = 1;
			
			continue;
		}
		
		if(c != ' ')
			continue;
		
		c = getchar();
		
		if(c != l && c != L)
			k = 0;		
	}

	return 0;
}
