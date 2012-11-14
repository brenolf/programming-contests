#include <iostream>
#include <map>

using namespace std;

typedef struct {
	string nome, sobre, tel;
} Data;

int main(){
	
	string read, com;
	map<int, Data> db;
	int op = 0;	
	
	Data d;
	d.nome = "s";
	d.sobre = "u";
	d.tel = "u";
	
	db[1] = d;
	
	while(cin >> read){
		if(!op){
			com = read;
			op = 1;
		}else{
			if(com == "add"){
				
			}
		}
	}

	return 0;
}
