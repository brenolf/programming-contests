#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int i = 0, n = 0, m = 0, r = 0, same = 0;
	double v = 0;
	
	while(1){
		scanf("%lf %d %d", &v, &n, &m);
		
		if(!v && !n && !m)break;
		
		if(m%10000 == n%10000)r = 3000;
		else if(m%1000 == n%1000)r = 500;
		else if(m%100 == n%100)r = 50;
		else{
			r = 0;
			m = m%100;
		
			if(n==0)n = 100;
			if(m==0)m = 100;
			
			same = 0;
			
			for(i=1;i<101;i+=4){
				if(n>=i && n<=i+3){
					if(m>=i && m<=i+3)same = 1;
					break;
				}
			}
			
			if(same)r = 16;
		}
		
		printf("%.2lf\n", v * r);
	}

	return 0;
}
