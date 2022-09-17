#include <stdio.h>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

#define MOD 998244353ll
ll ten[10010000], one[10010000];
int main(){
	int n, q;
	cin >> n>> q;
	ten[0] = 1;
	rep(i,1000100){
		ten[i+1] = ten[i] * 10 % MOD;
	}
	one[0] = 0;
	rep(i,1001000) one[i+1] = (one[i]*10+1)%MOD;
}
