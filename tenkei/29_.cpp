#include <stdio.h>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int op(int a, int b){
	return max(a,b);
}
int e(){
	return 0;
}
int mapping(int a, int b){
	return max(a,b);
}
int composition(int a, int b){
	return max(a,b);
}
int id(){
	return -1;
}
int main(){
	int w,n;
	cin>>w>>n;
	lazy_segtree<int,op,e,int,mapping,composition,id> seg(w);

	rep(i,n){
		int l,r;
		cin>>l>>r;
		int h=seg.prod(l-1,r);
		h++;
		cout << h << endl;
		seg.apply(l-1,r,h);
	}
}
