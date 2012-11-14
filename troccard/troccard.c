#include <stdio.h>
#define MAX 10001
#define MAXQ 100001


int main(){

	int ma[MAX], mb[MAX], qa[MAXQ], qb[MAXQ];
	int a = 0, b = 0, i = 0, j = 0, r = 0, T = 0;
	int ta = 0, tb = 0;

	while(1){
		scanf("%d %d", &a, &b);
		getchar();

		if(!a && !b)
			break;

		ta = 0;
		tb = 0;

		for(i = 0; i < a; i++){
			scanf("%d", &r);
			getchar();

			if(!qa[r])
				ma[ta++] = r;
			qa[r] = 1;
		}

		for(i = 0; i < b; i++){
			scanf("%d", &r);
			getchar();

			if(!qb[r])
				mb[tb++] = r;
			qb[r] = 1;
		}

		T = 0;

		if(ta < tb){
			for(i = 0; i < ta; i++){
				if(!qb[ma[i]])
					T++;
			}
			printf("%d\n", T);
		}else{
			for(i = 0; i < tb; i++){
				if(!qa[mb[i]])
					T++;
			}
			printf("%d\n", T);
		}

		for(i = 0; i < ta; i++)
			qa[ma[i]] = 0;


		for(i = 0; i < tb; i++)
			qb[mb[i]] = 0;
	}

	return 0;
}