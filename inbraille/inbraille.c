#include <stdio.h>
#include <stdlib.h>
#define M 101

char braile[10][7] = {".***..", "*.....", "*.*...", "**....", "**.*..", "*..*..", "***...", "****..", "*.**..", ".**..."};

inline int getBraile(char c0, char c1, char c2, char c3){
	
	int i  = 0;
	
	for(i = 0; i < 10; i++)
		if(braile[i][0] == c0 && braile[i][1] == c1 && braile[i][2] == c2 && braile[i][3] == c3)
			return i + 48;	
}

int main(){
	
	int i = 0, j = 0, D = 0, num = 0;
	char o, r1, r2, str[M], **read = (char**) malloc(sizeof(char*) * 3);
	
	for(i = 0; i < 3; i++)
		read[i] = (char*) malloc(sizeof(char) * M * 3);
	
	while(1){
	
		scanf("%d", &D);
		getchar();
		
		if(!D)
			break;

		
		scanf("%c", &o);
		getchar();
		
		if(o == 'B'){
			
			for(i = 0; i < 3; i++)
				gets(read[i]);
			
			for(i = 0; i < D * 3; i+=3)
				printf("%c", getBraile(read[0][i], read[0][i+1], read[1][i], read[1][i+1]));
			
		}else{
			
			gets(str);
			
			for(i = 0; i < 3; i++){
				for(j = 0; j < D; j++){
					num = str[j] - 48;

					printf("%c%c", braile[num][2 * i], braile[num][2 * i + 1]);
					
					if(j + 1 < D)
						printf(" ");
				}
				
				if(i < 2)
					printf("\n");
					
			}
		}
		
		printf("\n");
		
	}

	return 0;
}
