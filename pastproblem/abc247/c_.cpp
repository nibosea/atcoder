#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; 
	cin >> n; 
	for(int i = 1;i<(1<<n);i++){
		cout << __builtin_ctz(i) +1;
		if(i < (1<<n)-1){
			cout << ' ';
		}
	}
	cout << endl;
}
