// Breno Lima de Freitas 408433

#include <stdio.h>

int main(){
	int n = 0, w = 0;
	long long t = 0, r = 0;

	while(1){
		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		r = 0;
		t = 0;

		while(n--){
			scanf("%d", &w);
			getchar();

			t += w;
			r += (t > 0 ? t : -t);
		}

		printf("%lld\n", r);
	}

	return 0;
}