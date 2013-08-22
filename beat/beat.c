// UVA Beat the Spread!
#include <stdio.h>

int main(){
	int t, s, d, a, b, r;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &s, &d);

		r = (s - d);

		if(d > s || r % 2 != 0)
			printf("impossible\n");

		else {
			a = r / 2;
			b = s - a;

			if(a > b)
				printf("%d %d\n", a, b);
			else
				printf("%d %d\n", b, a);
		}
	}

	return 0;
}