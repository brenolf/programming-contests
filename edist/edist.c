#include <stdio.h>
#include <stdlib.h>
#define MAX 2001

int min(int a, int b, int c){
	if(b < a)
		a = b;
	
	return a < c ? a : c;
}

int len(char *str){
	int i = 0;
	
	while(str[i])
		i++;
	
	return i;
}

int main(){
	int **M = (int**) calloc(MAX, sizeof(int*));
	
	int T = 0, i = 0, j = 0, lenA = 0, lenB = 0, last = 0;
	char A[MAX], B[MAX];

	for(i = 0; i < MAX; i++)
		M[i] = (int*) calloc(MAX, sizeof(int));

	scanf("%d", &T);
	
	while(T--){
		scanf("%s", A);
		scanf("%s", B);
	
		lenA = len(A);
		lenB = len(B);
		
		//Se B é vazia
		for(i = 1; i <= lenA; i++)
			M[i][0] = i;
			
		//Se A é vazia
		for(j = 1; j <= lenB; j++)
			M[0][j] = j;
	
		for(i = 1; i <= lenA; i++){
			for(j = 1; j <= lenB; j++){
				//Último char de A com B
				last = A[i - 1] == B[j - 1] ? 0 : 1;
				
				//Distância = menor entre:
					// a distancia sem os ultimos chars com a comparacao entre eles
					// tirar um caractere de A
					// tirar um caractere de B
					
				M[i][j] = min(M[i - 1][j - 1] + last, M[i - 1][j] + 1, M[i][j - 1] + 1);
			}
		}
		
		printf("%d\n", M[lenA][lenB]);
	}
	
	return 0;
}
