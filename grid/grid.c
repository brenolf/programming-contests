// UVA Grid Successors
#include <stdio.h>
#include <stdlib.h>

void copy(int **mf, int **m){
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			mf[i][j] = m[i][j];
}

int infinity(int **mf){
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(mf[i][j] != 0)
				return 0;
	return 1;
}

int** f(int **g){
	int **gl = (int **) malloc(sizeof(int*) * 3);

	gl[0] = (int *) malloc(sizeof(int) * 3);
	gl[1] = (int *) malloc(sizeof(int) * 3);
	gl[2] = (int *) malloc(sizeof(int) * 3);

	int i, j, s;

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			s = 0;

			if(i - 1 >= 0)
				s += g[i - 1][j];

			if(i + 1 < 3)
				s += g[i + 1][j];

			if(j - 1 >= 0)
				s += g[i][j - 1];

			if(j + 1 < 3)
				s += g[i][j + 1];

			gl[i][j] = s % 2;
		}
	}

	return gl;
}

int** fi(int i, int **g){
	int **gl = (int **) malloc(sizeof(int*) * 3);

	gl[0] = (int *) malloc(sizeof(int) * 3);
	gl[1] = (int *) malloc(sizeof(int) * 3);
	gl[2] = (int *) malloc(sizeof(int) * 3);

	if(i == 0){
		copy(gl, g);
		return gl;
	}

	return f(fi(i - 1, g));
}

int main(){

	int t = 0, i, j, **m;

	m = (int **) malloc(sizeof(int*) * 3);

	m[0] = (int *) malloc(sizeof(int) * 3);
	m[1] = (int *) malloc(sizeof(int) * 3);
	m[2] = (int *) malloc(sizeof(int) * 3);

	scanf("%d", &t);
	getchar();

	while(t--){
		getchar();

		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){
				scanf("%1d", &m[i][j]);
			}
			getchar();
		}

		for(i = 0; !infinity(fi(i, m)); i++);

		printf("%d\n", i - 1);
	}

	for(i = 0; i < 3; i++)
		free(m[i]);
	free(m);

	return 0;
}