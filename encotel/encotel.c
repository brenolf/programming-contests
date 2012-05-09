#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char t[31];
	int i = 0, r[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8 ,8 ,8, 9, 9, 9, 9};
	
	while(scanf("%s", t)!=EOF){
		
		for(i=0;i<strlen(t);i++){
			if(t[i]>=65 && t[i]<=90)printf("%c", r[t[i]-65] + 48);
			else printf("%c", t[i]);
		}
		
		printf("\n");
	}

	return 0;
}
