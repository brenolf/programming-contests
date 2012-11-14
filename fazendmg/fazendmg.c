#include <stdio.h>
#define MAX 1600

int M[MAX][MAX];

int main(){
	int n = 0, x = 0, y = 0, l = 0, c = 0, i = 0, j = 0, a = 0, p = 0, maiorc = 0, maiorl = 0, menorc = 0, menorl = 0;

	while(1){

		scanf("%d", &n);

		if(!n)
			break;

		for(i = 0; i < MAX; i++)
			for(j = 0; j < MAX; j++)
				M[i][j] = 0;


		maiorl = -1;
		maiorc = -1;
		menorl = MAX;
		menorc = MAX;

		while(n--){
			scanf("%d %d %d %d", &x, &y, &l, &c);

			if(x + l > maiorl)
				maiorl = x + l;

			if(y + c > maiorc)
				maiorc = y + c;

			if(x < menorl)
				menorl = x;

			if(y < menorc)
				menorc = y;

			for(i = x; i < x + l; i++)
				for(j = y; j < y + c; j++)
					M[i][j] = 1;
		}

		a = 0;
		p = 0;

		for(i = menorl; i < maiorl; i++){
			for(j = menorc; j < maiorc; j++){
				if(M[i][j]){
					a++;
					p += 4;

					if(j > 0 && M[i][j - 1])
						p--;
					if(j < MAX - 1 && M[i][j + 1])
						p--;
					if(i > 0 && M[i - 1][j])
						p--;
					if(i < MAX - 1 && M[i + 1][j])
						p--;
				}
			}
		}

		printf("%d %d\n", a, p);
	}

	return 0;
}