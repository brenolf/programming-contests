#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int h = 0, m = 0, s = 0, c = 0, t = 0, hd = 0, md = 0, sd = 0, cd = 0;
	
	while(scanf("%2d%2d%2d%2d", &h, &m, &s, &c)!=EOF){
		t = c+(s*100)+(m*60*100)+(h*60*60*100);
		
		t = t/0.864;
		
		cd = t%100;
		t/=100;
		
		sd = t%100;
		t/=100;
		
		md = t%100;
		t/=100;
		
		hd = t;
		
		printf("%d%.2d%.2d%.2d\n", hd, md, sd, cd);
	}

	return 0;
}
