#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

typedef struct {
	char nome[50];
	int h;
} Pessoa;

int cmp(const void *pa, const void *pb){
	Pessoa a = *(Pessoa*)pa, b = *(Pessoa*)pb;
	return b.h - a.h;
}

int cmpStr(const void *pa, const void *pb){
	Pessoa a = *(Pessoa*)pa, b = *(Pessoa*)pb;
	return strcmp(a.nome, b.nome);
}

int main(){
	int n = 0, i = 0, j = 0, t = 0, c = 0, k = 1;
	Pessoa sala[MAX], time[MAX];

	scanf("%d %d", &n, &t);
	
	for(i = 0; i < n; i++)
		scanf("%s %d", sala[i].nome, &sala[i].h);
	
	qsort(sala, n, sizeof(Pessoa), cmp);
	
	for(i = 0; i < t; i++){
		printf("Time %d\n", k++);
		
		c = 0;
		
		for(j = i; j < n; j += t)
			time[c++] = sala[j];
			
		qsort(time, c, sizeof(Pessoa), cmpStr);
		
		for(j = 0; j < c; j++)
			printf("%s\n", time[j].nome);
		
		printf("\n");
	}
	
	return 0;
}
