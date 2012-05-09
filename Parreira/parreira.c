#include <stdio.h>

int map[501][501], 
N = 0, M = 0, 
L = 0, U = 0, D = 0;

int fromLine(int n){
	int e = 0, d = M - 1, m = 0, x = 0;
	
	while(e <= d){
		m = (e + d) / 2;
		x = map[n][m]; 
		
		if(x == L)
			return m;
		else if(x > L)
			d = m - 1;
		else
			e = m + 1;
	}
	
	return e >= M ? M - 1 : e;
}

int fromDiag(int fromCol){
	int e[] = {0, fromCol}, d[] = {M - 1 - fromCol, M - 1}, m[] = {0, 0}, x = 0;
	
	while(e[1] <= d[1]){
		m[0] = (e[0] + d[0]) / 2;
		m[1] = (e[1] + d[1]) / 2;
		
		x = map[m[0]][m[1]]; 
		
		if(x == U)
			return m[1];
		else if(x > U){
			d[0] = m[0] - 1;
			d[1] = m[1] - 1;
		}else{
			e[0] = m[0] + 1;
			e[1] = m[1] + 1;
		}
	}
	
	return e[1] >= M ? M - 1 : e[1];
}

int checkDiagonal(){
	int i = 0, colFrom = 0, colTo = 0, R = 0;
	
	D = -1;
	
	for(; i < N && N - i > D; i++){
		
		colFrom = fromLine(i);
		colTo = fromDiag(colFrom);
		
		printf("<%d %d>\n", colFrom, colTo);
		
		R = colTo - colFrom;
		
		if(R > D)
			D = R;
	}
	
	return D + 1;
}

int main(){
	
	int i = 0, j = 0, q = 0;
	
	while(1){
	
		scanf("%d %d", &N, &M);
	
		if(!N && !M)break;
	
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				scanf("%d", &map[i][j]);
	
		scanf("%d", &q);
	
		while(q--){
			scanf("%d %d", &L, &U);
			printf("%d\n", checkDiagonal());
		}
		
		printf("-\n");
		
	}
	
	return 0;
}
