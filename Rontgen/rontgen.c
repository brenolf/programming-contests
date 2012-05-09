#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char e[2000001], s[2000001], a;
	int n = 0, i = 0, q = 0, j = 0, t = 0, c = 0;
	
	scanf("%d", &n);
	
	while(n-->0){
		scanf("%s %d", e, &q);
		
		printf("%s\n", e);
		
		for(i=0;i<q;i++){
			c = 0;
			t = 0;
		
			for(j=0;j<strlen(e);j++){
				if(!j){
					a = e[j];
					t++;				
				}else{
					if(e[j]!=a){
						s[c++] = t + 48;
						s[c++] = a;
						
						a = e[j];
						t = 1;
					}else t++;
				}
				
				if(j+1>=strlen(e)){
					s[c++] = t + 48;
					s[c++] = a;
				}
			}
			
			s[c] = '\0';
			strcpy(e, s);
			
			printf("%s\n", e);
		}
		printf("\n");
	}
	
	return 0;
}
