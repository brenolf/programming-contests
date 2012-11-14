#include <stdio.h>
#include <string.h>
#define MAX 101
#define LEN 11

int E = 0;
char esp[MAX][LEN], str[MAX];

inline char toLowerCase(char c){
	if(c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

inline char toUpperCase(char c){
	if(c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}

inline int isSpecial(int j){
	while(j < MAX)
		str[j++] = '\0';

	int i = 0;
	for(i = 0; i < E; i++)
		if(!strcmp(esp[i], str))
			return i;
	return -1;
}

int main(){
	int n = 0, e = 0, f = 0, i = 0, j = 0, spc = 0, specialID = 0;
	char c;

	scanf("%d", &n);
	getchar();

	while(n--){
		scanf("%d %d", &e, &f);
		getchar();

		E = e;
		i = 0;
		j = 0;

		while(e){
			scanf("%c", &c);

			if(c == ' ' || c == '\n'){
				while(j < LEN)
					esp[i][j++] = '\0';

				e--;
				i++;
				j = 0;
				continue;
			}

			esp[i][j++] = toLowerCase(c);
		}

		j = 0;
		spc = 0;

		while(f){
			scanf("%c", &c);

			if(c == '\n' || c == ' ' || c == ':' || c == '-'){
				specialID = isSpecial(j);

				if(specialID < 0){
					if(j)
						printf("%c", toUpperCase(str[0]));
				}else if(spc)
					printf("%c", esp[specialID][0]);

				j = 0;

				if(c == '\n'){
					spc = 0;
					f--;
					printf("\n");
				}else
					spc++;
				
				continue;
			}

			str[j++] = toLowerCase(c);
		}

		printf("\n");
	}

	return 0;
}
