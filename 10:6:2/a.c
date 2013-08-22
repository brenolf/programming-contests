// UVA 10:6:2
#include <stdio.h>
#include <math.h>

int main(){
	double PI = acos(-1);
	int t = 0;
	double n;

	scanf("%d", &t);

	while(t--){
		scanf("%lf", &n);

		//10:6 and 5:1

		double circle = (n / 5) * (n / 5) * PI;
		double rect = ((n / 10) * 6) * n;

		printf("%.2lf %.2lf\n", circle, rect - circle);
	}

	return 0;
}