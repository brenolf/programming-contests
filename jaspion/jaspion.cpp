#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string palavras[82], jp, pt;
char *inp = (char*) calloc(82, sizeof(char));
int R = 0, LEN = 0;

inline void toJp(){
	fgets(inp, 82, stdin);

	int i = 0;
	jp = "";
	
	while(inp[i] != '\n' && inp[i] != '\0')
		jp += inp[i++];
}

inline void toPt(){
	fgets(inp, 82, stdin);

	int i = 0;
	pt = "";
	
	while(inp[i] != '\n' && inp[i] != '\0')
		pt += inp[i++];
}

inline void getWords(){
	fgets(inp, 82, stdin);

	LEN = 0;
	int i = 0;
	
	palavras[LEN] = "";
	
	while(inp[i] != '\n' && inp[i] != '\0'){
	
		if(inp[i] == ' '){
			LEN++;
			palavras[LEN++] = " ";
			palavras[LEN] = "";
		}else
			palavras[LEN] += inp[i];
			
		i++;
		
	}
	
	if(!palavras[LEN].empty())
		LEN++;
}

int main(){
	
	int t = 0, m = 0, n = 0, i = 0, j = 0, k = 0;
	
	map<string, string> dic;
	map<string, string>::iterator it;

	scanf("%d", &t);
	
	getchar();
	
	while(t--){
		dic.clear();
	
		scanf("%d %d", &m, &n);
		
		getchar();
		
		for(i = 0; i < m; i++){
			toJp();
			toPt();
			dic[jp] = pt;
		}
		
		
		for(i = 0; i < n; i++){
			getWords();
		
			for(j = 0; j < LEN; j++){
				it = dic.find(palavras[j]);
			
				if(it != dic.end())
					cout << it -> second;
				else
					cout << palavras[j];
			}
			cout << endl;
		}
	}

	return 0;
}
