#include <stdio.h>
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int op(int a,int b){
	return max(a,b);
}

int e(){
	return 0;
}

int mapping(int a,int b){
	return max(a,b);
}

int composition(int a,int b){
	return max(a,b);
}

int id(){
	return -1;
}

int main(){
	int W,N;
	cin>>W>>N;
	
	lazy_segtree<int,op,e,int,mapping,composition,id> seg(W);
	
	rep(i,N){
		int L,R;
		scanf("%d %d",&L,&R);
		int h = seg.prod(L-1,R);
		h++;
		printf("%d\n",h);
		seg.apply(L-1,R,h);
	}
	
	
	
	return 0;
}
