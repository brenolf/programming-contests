#include <stdio.h>

int main(){
	int n = 0, i = 0;
	int intervalos[5][2] = {{0, 0}, {1, 35}, {36, 60}, {61, 85}, {86, 100}};
	
	scanf("%d", &n);

	for(i = 0; i < 5; i++){
		if(n >= intervalos[i][0] && n <= intervalos[i][1]){
			printf("%c", ('E' - i));
			break;
		}
	}
	
	return 0;
}
