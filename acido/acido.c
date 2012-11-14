#include <stdio.h>

int main(){
	
	char c, b, bases[301];
	int R = 0, top = 0;
	
	while((c = getchar()) != EOF){
		if(c == '\n'){
			printf("%d\n", R);
			R = 0;
			top = 0;
		}else{
			if(top > 0){
				b = bases[top - 1];
				if((c == 'B' && b == 'S') || (c == 'S' && b == 'B') || (c == 'C' && b == 'F') || (c == 'F' && b == 'C')){
					top--;
					R++;
					continue;
				}
			}
			
			bases[top++] = c;
		}
	}
	
	return 0;
}
