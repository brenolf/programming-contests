#include <stdio.h>
#include <string.h>

char str[130];
char team[13050], judge[13050];

int numerically_equal(char a[13050], char b[13050]){
	char aa[13050], bb[13050];
	int i, j;

	for(i = 0, j = 0; i < 13050; i++){
		if(a[i] == '\0'){
			aa[j] = '\0';
			break;
		}

		if(a[i] >= '0' && a[i] <= '9')
			aa[j++] = a[i];
	}

	for(i = 0, j = 0; i < 13050; i++){
		if(b[i] == '\0'){
			bb[j] = '\0';
			break;
		}

		if(b[i] >= '0' && b[i] <= '9')
			bb[j++] = b[i];
	}

	return (strcmp(aa, bb) == 0);
}

int main(){
	
	int n, m, i, e, k = 1, pe;

	while(1){

		scanf("%d", &n);
		getchar();

		if(!n)
			break;

		strcpy(team, "");
		strcpy(judge, "");

		for(i = 0; i < n; i++){
			fgets(str, 130, stdin);
			str[strlen(str)] = '\0';
			strcat(team, str);
		}

		scanf("%d", &m);
		getchar();

		for(i = 0; i < m; i++){
			fgets(str, 130, stdin);
			str[strlen(str)] = '\0';
			strcat(judge, str);
		}

		if(strcmp(team, judge) == 0)
			printf("Run #%d: Accepted\n", k++);
		else if(numerically_equal(team, judge))
			printf("Run #%d: Presentation Error\n", k++);
		else
			printf("Run #%d: Wrong Answer\n", k++);	

	}

	return 0;
}