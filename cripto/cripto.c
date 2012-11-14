#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

typedef struct {
	char c;
	int q;
} Letra;

int cmp(const void *a, const void *b){
	Letra la = *(Letra*)a, lb = *(Letra*)b;
	int dif = lb.q - la.q;

	if(dif)
		return dif;

	return la.c - lb.c;
}

Letra freq[27];
char seq[27];

inline char getLetra(char c){
	if(c == ' ')
		return c;

	int i = 0;

	for(i = 0; i < 26; i++){
		if(freq[i].c == c)
			return seq[i];
	}
}

int main(){

	int i = 0, t = 0, f = 0, k = 1, len = 0;
	char cif[MAX];

	while(1){
		scanf("%d %d", &t, &f);
		getchar();

		if(!t && !f)
			break;

		freq[0].c = 'a';
		freq[0].q = 0;

		for(i = 1; i < 26; i++){
			freq[i].c = freq[i - 1].c + 1;
			freq[i].q = 0;
		}

		scanf("%s", seq);
		getchar();

		for(i = 0; i < t; i++){
			scanf("%c", &cif[i]);

			if(cif[i] != ' ')
				freq[cif[i] - 'a'].q++;
		}

		getchar();


		qsort(freq, 26, sizeof(Letra), cmp);

		printf("Teste %d\n", k++);

		for(i = 0; i < t; i++)
			printf("%c", getLetra(cif[i]));

		printf("\n\n");

	}


	return 0;
}