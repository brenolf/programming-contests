#include <iostream>
#include <map>

using namespace std;


int main(){
	
	map<int, int> M;
	int n = 0, i = 0, r = 0, R = 0, MX = 0;
	
	cin >> n;
	
	for(i = 0; i < n; i++){
		cin >> r;
		M[r]++;
		
		if(!i || M[r] > MX){
			R = r;
			MX = M[r];
		}
	}
	
	cout << R;

	return 0;
}
