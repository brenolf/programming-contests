// UVA I <3 pizza
#include <stdio.h>

int m, a, r, g, i, t;

void ingredient(char l){
	switch(l){
		case 'M': m++; break;
		case 'A': a++; break;
		case 'R': r++; break;
		case 'G': g++; break;
		case 'I': i++; break;
		case 'T': t++; break;
	}
}

int margarita(){
	if(m >= 1 && a >= 3 && r >= 2 && g >= 1 && i >= 1 && t >= 1){
		m--;
		a -= 3;
		r -= 2;
		g--;
		i--;
		t--;
		return 1;
	}

	return 0;
}

int main(){
	
	int n, j;

	scanf("%d", &n);
	getchar();

	while(n--){
		char c;

		m = a = r = g = i = t = 0;

		while((c = getchar()) != '\n')
			ingredient(c);

		for(j = 0; margarita(); j++);

		printf("%d\n", j);
	}


	return 0;
}